/* Name : gameTimes.h	ver 1.0
 * Content : 게임 횟수, 승률
 * Implementation : PHS
 *
 * Last modified 2018/12/30
 */
#ifndef __GAMETIMES_H__
#define __GAMETIMES_H__

void GameCount(int * gameCount);
void YouWin(int com, int you, int * youWin);
int WinRate(int * gameCount, int * youwin);

#endif
/* end of file */
