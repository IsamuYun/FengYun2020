// wiz_b.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("巫师留言板", ({ "board" }) );
       
        set("board_id", "wiz_b");
        set("long", "这是一块专供巫师使用的留言板。\n" );
        setup();
        set("capacity", 30);			// 容量为30张留言
        replace_program(BULLETIN_BOARD);
}
