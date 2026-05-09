#include "Commands.hpp"
#include "../Server.hpp"
#include "../Client.hpp"
#include "../Reply.hpp"
#include "../Channel.hpp"
#include "../Utils.hpp"

void cmd_privmsg(Server &srv, Client &cli, const Message &msg)
{
	if (cli.getState() != Client::STATE_REGISTERED) {
		srv.sendTo(cli, Reply::err_notregistered(srv.getName(), cli));
		return;
	}
	if (msg.params.empty()) {
		srv.sendTo(cli, Reply::err_norecipient(srv.getName(), cli, "PRIVMSG"));
		return;
	}
	if (msg.params.size() < 2) {
		srv.sendTo(cli, Reply::err_notexttosend(srv.getName(), cli));
		return;
	}

	const std::string &target = msg.params[0];
	const std::string &text = msg.params[1];
	std::string fullMsg = ":" + cli.getPrefix() + " PRIVMSG " + target + " :" + text + "\r\n";

	// Channel message
	if (target[0] == '#' || target[0] == '&') {
		Channel *chan = srv.findChannel(target);
		if (!chan) {
			srv.sendTo(cli, Reply::err_nosuchnick(srv.getName(), cli, target));
			return;
		}
		if (!chan->isMember(&cli)) {
			srv.sendTo(cli, Reply::err_cannotsendtochan(srv.getName(), cli, target));
			return;
		}
		chan->broadcast(fullMsg, &cli);
		srv.enableWriteAll(*chan, &cli);
	} else {
		// User message
		Client *dest = srv.findClientByNick(target);
		if (!dest) {
			srv.sendTo(cli, Reply::err_nosuchnick(srv.getName(), cli, target));
			return;
		}
		srv.sendTo(*dest, fullMsg);
	}
}

void cmd_notice(Server &srv, Client &cli, const Message &msg)
{
	if (cli.getState() != Client::STATE_REGISTERED)
		return; // NOTICE never generates errors
	if (msg.params.size() < 2)
		return;

	const std::string &target = msg.params[0];
	const std::string &text = msg.params[1];
	std::string fullMsg = ":" + cli.getPrefix() + " NOTICE " + target + " :" + text + "\r\n";

	if (target[0] == '#' || target[0] == '&') {
		Channel *chan = srv.findChannel(target);
		if (!chan || !chan->isMember(&cli))
			return;
		chan->broadcast(fullMsg, &cli);
		srv.enableWriteAll(*chan, &cli);
	} else {
		Client *dest = srv.findClientByNick(target);
		if (!dest)
			return;
		srv.sendTo(*dest, fullMsg);
	}
}
