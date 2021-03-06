/****************************************************************
 * This file is a part of the TianXia(天下, The World)'s MudLib.*
 * Please retain the header if you use it.     -- Micro@TianXia *
 ****************************************************************/

// File     : torch.c
// Purpose  : 火把
// Created  : 1998-08-03
// By       : Micro@TianXia

// History  : 98-08-03  Micro@TianXia 创建文件

#include <ansi.h>

inherit ITEM;

// 函数：物体生成函数
void create()     
{
	set_name( "火把", ({ "torch" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枝");
		set("long", @LONG
这是一枝火把。它是最常用的照明工具。
你可以用 light 来点着它，用 unlight 来熄来它。
LONG
                );
          	set("value", 100);
        	set("fuel", 600);       // 可以燃烧的时间秒数
	}
}

// 函数：物体初始化函数
void init()
{
	add_action("light_torch", "light");
	add_action("unlight_torch", "unlight");
}

// 函数：点燃火把的处理
int light_torch( string str )
{
	if( !id(str) ) return 0;
	if( !query("fuel") )
		return notify_fail( "这根火把已经烧完了。\n");

	if( query("light") ) 
		return notify_fail( "这根火把已经点燃了。\n");

	write("你将火把点亮。\n");
	set("light", 1);
	call_out( "burn_out", query("fuel") );
	return 1;
}

// 函数：熄灭火把的处理
int unlight_torch(string str)
{
	if( !id(str) ) return 0;
	if( !query("fuel") )
		return notify_fail("太迟了，这根火把已经烧完了。\n");

	if( !query("light") )
		return notify_fail("这根火把还没有点燃，如何熄灭？\n");

	write("你将火把熄灭。\n");
	set( "light", 0 );
	set( "fuel", remove_call_out("burn_out") );
	return 1;
}

// 函数：火把完全燃烧后的处理
void burn_out()
{
	object owner;

        // 提示火把已经烧完了
	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,"你的火把火光闪了几下，熄掉了。\n");

        // 烧完的火把没有价值，而且火光会熄灭
	set( "value", 0 );      
	set( "fuel", 0 );
	set( "light", 0 );
}

// 函数：火把的描述函数
// 注释：1.主要用来描述火把的三个状态：燃烧，熄灭，烧光。
string extra_long()
{
	if(query("fuel"))
		return "这把火把" + (query("light") ? "正燃烧着。\n" : "熄灭了。\n");
	return "这把火把已经烧光了。\n";
}

