inherit ITEM;
void create()
{
        set_name("≤ ªÊ»´±æΩ∆ø√∑", ({ "full-jpm" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±æ");
                set("long",
"[1;33m                        
      ,;'      ',, ;; ,,,,,,;,  ;;    ,;,
     ,;';,     ,;,,;,;,;;   ,   ;;   ,;;,,,,,
   ,;'   ';,,   ;; ;;  ;;'';;''';;'',;'    ,
,,';,,,,,,,';;' ;; ;;  ;;, ;;  ;;;,' ;;''';;'
      ;;  ,    ';;';;'';; ';; ,';; ;,;;,;,;;'
  ';'';;'';'    ;; ;;  ;;,,;; ; ;; ;';; ',;;
   ';,;; ,;'    ;; ;;  ;'' ;;   ;;   ;;,,,;;,
 ,,,;,;;;;,,;, ,'  ;'      ';'  ;;   '   ,;'[2;37;0m£®[1;31m≤ [1;32mªÊ[1;33m»´±æ[2;37;0m£©\n"                );
                set("value", 1);
                set("material", "paper");
        }
}
void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
	int sena;
	int cps;
	string book;
        me = this_player();
	cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("÷∏¡Ó∏Ò Ω£∫study < È> <…Ò ˝¡ø>\n");
        if( (string)book != "jinpingmei")
                return notify_fail("ƒ„“™∂¡ ≤˜·£ø\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("ƒ„“™∂¡ ≤˜·£ø\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "’˝–¿œ≤»ÙøÒµÿ∑≠∂¡◊≈" + ob->name()
                + "°£\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "∑≠¡À“ª“≥" + ob->name()
                + "£¨Ãß∆Õ∑”√…´√‘√‘—€…Ò…œ…œœ¬œ¬µƒ¥Ú¡ø◊≈ƒ„°£\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "∑…øÏµÿ∑≠∂¡◊≈" + ob->name()
                + "£¨£¢≈æ£¢µƒ“ª…˘£¨“ªµŒø⁄ÀÆµŒ‘⁄ È…œ°£\n", environment(me), me);
                        break;
        }
		write("
                    ÃÏœ¬µ⁄“ª∑Á¡˜–°Àµ

                      °∂Ω∆ø√∑°∑

\n");
	if( cps >20 )
	{	write("ƒ„‘Ω∂¡‘ΩœÎ∂¡£Æ£Æ£Æ\n");
		return 1;
	}
	if( cps >10)
        {       write("ƒ„∏–µΩ»´…Ì∑¢»»£¨‘Ω∂¡‘ΩœÎ∂¡£Æ£Æ£Æ\n");
                return 1;
        }
		write("ƒ„∏–µΩ“ªπ…»»∆¯¥”µ§ÃÔ÷±…˝∂¯∆£Æ£Æ£Æ\n");
		me->unconcious();
		return 1;

}
