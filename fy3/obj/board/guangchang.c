// guangchang.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("中央广场留言板", ({ "board" }) );
        set("location", "/d/center/guangchang");
        set("board_id", "guangchang");
        set("long", "这是一块放置在侠客城中央广场的留言板。\n" );
        setup();
        set("capacity", 50);			// 容量为50张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
