// xuelong2.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("留言板", ({ "board" }) );
        set("location", "/d/xuelongshanzhuang/dating");
        set("board_id", "xuelong2");
        set("long", @LONG
这是血龙山庄内部互通消息的留言板。
LONG
	);
	setup();
        set("capacity", 50);                    // 容量为50张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
