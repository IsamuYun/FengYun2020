// feishi.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("飞氏员工留言板", ({ "board" }) );
        set("location", "/d/feishijituan/2_office");
        set("board_id", "feishi");
        set("long", "这是飞氏集团专用的留言板。\n" );
        setup();
        set("capacity", 30);                    // 容量为30张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
