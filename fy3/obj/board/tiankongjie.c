
inherit BULLETIN_BOARD;

void create()
{
        set_name("天空界留言板", ({ "board" }) );
        set("location", "/d/tiankongjie/tiankongjie");
        set("board_id", "tiankongjie");
        set("long", "这是一块放置在天空界的留言板。\n" );
        setup();
        set("capacity", 50);                    // 容量为50张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
