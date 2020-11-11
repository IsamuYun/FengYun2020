// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","梦仙龛");
  set("long",@LONG
沿朝阳向东北去，便到梦仙龛，一路白云飘浮，山风阵阵，夹道树
木俱是百年松柏，郁郁苍苍，远处眺望，山烟弥漫，伴随阵阵凉风，不
由让人飘飘欲仙，相传这里是唐皇游山到此小憩，梦见碧霞元君的所在，
山林中立有小小一神龛，十分精致，想来也花费无数能工巧匠之力。远
处树木越来越密，再往东便是老云寨了。
LONG
  );
  set("exits",([
	"east" : "/d/oldpine/npath1",
	"westdown" : __DIR__"chaoyang",
               ]));


        set("outdoors", "fengyun");
	set("coor/x",-470);
	set("coor/y",-310);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}
