inherit ITEM;
void create()
{
   set_name("桌子", ({ "desk" , "桌子" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "个");
      set("long", "这是一张檀木桌，上面放着两本书。\n");
      set("value", 1);
   }
}
int is_container() { return 1; }
