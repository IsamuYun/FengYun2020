// test_npc.c 随机姓名NPC范例

#define NAME_D    "/cmds/arch/random_name"//可对应到你放random_name.c的具体路径

inherit NPC;

void create()
{
    mapping name;
    name = NAME_D->man_name();
/*如果要产生女性，则：
    name = NAME_D->woman_name();
如果要产生日本人，则：
	name = NAME_D->jap_name();
*/
    set_name(name["name"],({name["id"]}));
	set("gender", "男性" );//性别与上面对应
//以下随便设
   	set("age",30+random(30));
   	set("attitude", "peaceful");
    set("quest_npc",1);

    set("str", 25);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

    set("combat_exp",1000);	
    setup();
}
