inherit EQUIP;
void create()
{
        set_name("人皮面具", ({ "skinmask" }) );
        set_weight(600);
                set("unit", "个");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"Tianji"}) );
                set("armor_prop/name", ({"[1;33m天机老人[2;37;0m"}) );
                set("armor_prop/short", ({"[1;33m天机老人[2;37;0m(Tianji)"}) );
}
