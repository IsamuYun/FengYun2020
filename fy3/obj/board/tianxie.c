// tianxie.c
// by zen

inherit BULLETIN_BOARD;

void create()
{
        set_name("天邪派留言板", ({ "board" }) );
        set("location", "/d/tianxie/tianxiepai/main-03");
        set("board_id", "tianxie");
        set("long", "这是天邪派弟子专用的留言板。\n" );
        setup();
        set("capacity", 50);                    // 容量为30张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
