// towiz_b.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("玩家意见留言板", ({ "board" }) );
        set("location", "/d/wizard/guest_room");
        set("board_id", "towiz_b");
        set("long", "这是一块专供玩家和巫师交留的留言板。\n" );
        setup();
        set("capacity", 50);			// 容量为50张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
