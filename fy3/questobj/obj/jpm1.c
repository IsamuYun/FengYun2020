inherit ITEM;
void create()
{
        set_name("�ʻ�ȫ����ƿ÷", ({ "full-jpm" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"[1;33m                        
      ,;'      ',, ;; ,,,,,,;,  ;;    ,;,
     ,;';,     ,;,,;,;,;;   ,   ;;   ,;;,,,,,
   ,;'   ';,,   ;; ;;  ;;'';;''';;'',;'    ,
,,';,,,,,,,';;' ;; ;;  ;;, ;;  ;;;,' ;;''';;'
      ;;  ,    ';;';;'';; ';; ,';; ;,;;,;,;;'
  ';'';;'';'    ;; ;;  ;;,,;; ; ;; ;';; ',;;
   ';,;; ,;'    ;; ;;  ;'' ;;   ;;   ;;,,,;;,
 ,,,;,;;;;,,;, ,'  ;'      ';'  ;;   '   ,;'[2;37;0m��[1;31m��[1;32m��[1;33mȫ��[2;37;0m��\n"                );
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
                return notify_fail("ָ���ʽ��study <��> <������>\n");
        if( (string)book != "jinpingmei")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("��Ҫ��ʲ�᣿\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "����ϲ����ط�����" + ob->name()
                + "��\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "����һҳ" + ob->name()
                + "��̧��ͷ��ɫ���������������µĴ������㡣\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "�ɿ�ط�����" + ob->name()
                + "����ž����һ����һ�ο�ˮ�������ϡ�\n", environment(me), me);
                        break;
        }
		write("
                    ���µ�һ����С˵

                      ����ƿ÷��

\n");
	if( cps >20 )
	{	write("��Խ��Խ���������\n");
		return 1;
	}
	if( cps >10)
        {       write("��е�ȫ�����ȣ�Խ��Խ���������\n");
                return 1;
        }
		write("��е�һ�������ӵ���ֱ�����𣮣���\n");
		me->unconcious();
		return 1;

}
