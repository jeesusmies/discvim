#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "include/discord_rpc.h"

const char *applicationId = "741571172294197368";

void InitDiscord() {
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));

	Discord_Initialize(applicationId, &handlers, 1, NULL);
}

void UpdatePresence() {
	time_t start = time(0);
	for(;;) {
		char buffer[2][128];
		
		FILE *f_edit;
		FILE *f_file;
		
		f_edit = fopen("/tmp/discvim_editing.txt", "r");
		f_file = fopen("/tmp/discvim_file.txt", "r");
		
		if(!f_edit || !f_file) {
			return;
		}

		fgets(buffer[0], sizeof(buffer[0]), f_edit);
		fgets(buffer[1], sizeof(buffer[1]), f_file);

		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));

		if (!strcmp(buffer[0], "Editing\n")) {
			discordPresence.details = "Editing: unnamed file";
		} else {
			char t[128];
			sprintf(t, "%s%s", "Editing: ", buffer[1]);
			discordPresence.details = t;
		}
      
		discordPresence.largeImageKey = "logo";
		discordPresence.largeImageText = "DISCVIM";
		discordPresence.smallImageKey = "logo";
		discordPresence.smallImageText = "add me kissa#0500";

      		discordPresence.startTimestamp = start;
		discordPresence.instance = 1;

		Discord_UpdatePresence(&discordPresence);
		Discord_RunCallbacks();
		sleep(2);
	}	
}

int main(void) {
	InitDiscord();

	UpdatePresence();

	Discord_Shutdown();

}
