inherit ITEM;
void create()
{
        set_name("��ƿ÷", ({ "jpm" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"                        
      ,;'      ',, ;; ,,,,,,;,  ;;    ,;,
     ,;';,     ,;,,;,;,;;   ,   ;;   ,;;,,,,,
   ,;'   ';,,   ;; ;;  ;;'';;''';;'',;'    ,
,,';,,,,,,,';;' ;; ;;  ;;, ;;  ;;;,' ;;''';;'
      ;;  ,    ';;';;'';; ';; ,';; ;,;;,;,;;'
  ';'';;'';'    ;; ;;  ;;,,;; ; ;; ;';; ',;;
   ';,;; ,;'    ;; ;;  ;'' ;;   ;;   ;;,,,;;,
 ,,,;,;;;;,,;, ,'  ;'      ';'  ;;   '   ,;'    ��ȫ����

�������ͼ����˺���ˡ�
\n"                );
                set("value", 1);
                set("material", "paper");
        }
}

void init()
  {
     if(this_player()==environment())
     add_action("do_ding","zhan");
  }

int do_ding()
 {
   int i,he1=0,he2=0,he3=0;
   object jade,me, *inv;
   object zhu1,zhu2,zhu3;
   me = this_player();
   inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                   {
	 		if(inv[i]->query("name") == "����ͼ") {he1 = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "����") {he2 = 1; zhu2 = inv[i];}
			if(inv[i]->query("name") == "ëˢ") {he3 = 1; zhu3 = inv[i];}
		   }
if( he1 && he2 && he3 )
     {
	destruct(zhu1);
        destruct(zhu2);
        destruct(zhu3);
	jade = new("/questobj/obj/jpm1");
	jade->move(me);
message_vision("$N������ͼ����ճ�ص���ƿ÷�ϡ�\n",this_player());
	destruct(this_object());

     }
 else 
    message_vision("$N���϶���������������û��ϣ���ˡ�\n",this_player());
  return 1;
 }

