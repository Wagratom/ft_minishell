/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banners.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:11:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANNERS_H
# define BANNERS_H

# define WELCOME_BANNER "\
\033[0;33m/-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\\\033[0m\n\
\033[0;33m|\033[0;34m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                              .:~!?5J7!!?7!:.                   \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                          .:~!7JY??P5J7!7YG5J7^:.               \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                       .:~!!?7Y5J??J77YG55PJ?J!JY?!^:..         \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                     .:!?5Y~77J777?!!7?55Y!!7YY?7?YJ77?77!~~^:  \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                   ..!?7J7~~!7Y~~!7~!?7!7?77~^~!?JY7777^~^~^!.  \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                .:^!J???J!!~^!Y?~~7~~~77P?!J7^:~~~~~^::~^::^:   \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                              .^^~75GJ7?J77!!~!Y77Y!?7^J?!^!^~^~^:.:^:..:~~:    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                            .::^!!7!7~!?J77!~^~7!~~7!!~~::~^~~:^^!^::..:!!^.    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                          .:!:~7!?7^^^~J?J7~::~:J77^^^^!~^~^~:..:~:..:^!?~^.    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                        ..::~Y7~77^:::^!7JYJ~:::!JY^:7~^:^^!!7!^.:^..~77?!?.    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                      .^^:::^~!~J!!7P?!7?PGGP?::.:!~:.~^:^:.^J7~..^~~7?~!Y7.    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                     .~7^.::^JPJ?7YY~JY!5GB#&B~..:.:^::::.:.:~::.^!7G5~^!7!     \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                   .!?!7^:~5!?J7~^?~:~7~!?7?5#?:...:::^^:.:~:...::~~?7~~~7^     \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                  ^!!7757~Y&Y:7?!YY^^!!^:~^::^^:.~~: ..:7^!J^:.:^^??7!^!!~^     \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                .:!77^JY?YGB7:..:!!^:^7!^.....:.^!!::..  .:!^~^^~!Y!!!^~^J:     \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m              ....^557!7!777^.::::^:^!!^!^:..~^:!??~!~^^...:..^^~7~!^^:!!~      \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m            .:^:.::Y7!?J~^!^~:...:::777^YJ~~^!J!^?7^^^:^^:^^:::^^^~~~:^Y!.      \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m           :^:^:^:!7~^~!^^~!JJ!:^^^!77!^!7~^:^!!^~^....:::...::^~!!!!~!^        \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m          ^!7JY~77^..::^^7^7JJ5!!!:^~!^:~!~~7!!!~~^^~~~~~~!!77777!~!!:.         \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m        .^~~Y!~!!~......^!J?JP?!~7~!!~!~^^^^~^~!!7????????77777777^:.           \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m      .^~7?7?~^~7~^::^^77~^~7?7~~!7777??????JJJJJ???777!!!!!~?7~^:.             \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m     :?77J?7~!~7YJ7JJJYJ?JJ?JY555PPPP555YYJJ???777777!!~~~^^^:.                 \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m    ^GBP5YP5YJY5GB##&#######BBBGGP55YJJJ?77!~^::^:^!^:.                         \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m   ^G&BB###&@@@@@@@@&&&&#BBGGPP55YJJ??7?!::.                                    \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m   :..:YG#&&&&&&&&&&##BBGP55Y?77?!~^::.^                                        \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m       :!JG##&&&##BBP55Y!^:::^                                                  \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m        ~7JPGGP5J!~^^:^                                                         \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m       .~~^:::                                                                  \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\033[0m\n\
\033[0;33m|\033[0;36m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m                      __        __        /\\            __   __                 \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m               _____ |__| ____ |__| ______  |__   ____ |  | |  |                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m              /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m             |  | |  \\  |   |  \\  |\\___ \\|      \\  ___/_  |__  |__              \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m             |__|_|  /__|___|  /__|____  \\___|  /\\___  /____/____/              \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m                   \\/        \\/        \\/     \\/     \\/                         \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;34m                                            by lpaulo-m & wwallas-              \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;36m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;37m              - CONTROL+C: Reads new line                                       \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;37m              - CONTROL+D: Exits program cleanly                                \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;37m              - help: Print help message                                        \033[0;33m|\033[0m\n\
\033[0;33m|\033[0;37m                                                                                \033[0;33m|\033[0m\n\
\033[0;33m\\-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\033[0m\n\
\n\
"

#endif