#include"DxLib.h"
#include"map.h"

void InitMap(Map& map)
{
	LoadDivGraph("data/texture/tile1.png", 15, 5, 3, 64, 64, map.mapGraph);
}


void DrawMap(Map& map)
{
	//DrawGraph(0, 0, map.backgraph,true);

	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < map.widthchipnum; x++)
		{

				DrawGraph(x*64, y*64, map.mapGraph[map.g_MapChipList[y][x]],TRUE);
		}
	}
}