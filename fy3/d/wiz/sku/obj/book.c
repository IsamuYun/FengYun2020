// sku@00-11-19 
inherit ITEM;
void create()
{
	set_name("一本指令的小教材", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"rehash <目录名称>    这个指令会更新系统内部的指令表，如果你新增或删除了某个目录下的指令.\n" 
"exec (玩家>          将某个玩家踢出风云 并将其IP暂时BAN掉当风云重新REBOOT后，可以再连线\n"
"imprison <玩家>      将某个玩家禁锢在风云的监狱里，在监狱里什么也做不了一直到被提出监狱。\n"
"reclaim              将存在於记忆体里无用的变数清除掉, 以减少记忆体的使用。\n"
"localcmds            列出你身上及四周的物品与所在的环境提供的所有指令。\n"
"nuke <玩家>          将某个玩家踢出风云，并且使其在一个小时内不可以联线\n"
"uncon <生物>         使生物昏迷不醒\n"
"where <玩家的 ID>    这个指令是用来得知玩家目前所在的位置\n"
"halt                 可以停止所有与你(□)有关的战斗。\n");
		set("value", 1);
                set("no_drop", 1);
		set("material", "paper");
		}
}
