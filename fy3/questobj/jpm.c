inherit ITEM;
void create()
{
        set_name("金瓶梅", ({ "jpm" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"                        
      ,;'      ',, ;; ,,,,,,;,  ;;    ,;,
     ,;';,     ,;,,;,;,;;   ,   ;;   ,;;,,,,,
   ,;'   ';,,   ;; ;;  ;;'';;''';;'',;'    ,
,,';,,,,,,,';;' ;; ;;  ;;, ;;  ;;;,' ;;''';;'
      ;;  ,    ';;';;'';; ';; ,';; ;,;;,;,;;'
  ';'';;'';'    ;; ;;  ;;,,;; ; ;; ;';; ',;;
   ';,;; ,;'    ;; ;;  ;'' ;;   ;;   ;;,,,;;,
 ,,,;,;;;;,,;, ,'  ;'      ';'  ;;   '   ,;'    （全本）

但好象插图都被撕掉了。
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
	 		if(inv[i]->query("name") == "春宫图") {he1 = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "浆糊") {he2 = 1; zhu2 = inv[i];}
			if(inv[i]->query("name") == "毛刷") {he3 = 1; zhu3 = inv[i];}
		   }
if( he1 && he2 && he3 )
     {
	destruct(zhu1);
        destruct(zhu2);
        destruct(zhu3);
	jade = new("/questobj/obj/jpm1");
	jade->move(me);
message_vision("$N将春宫图重新粘回到金瓶梅上。\n",this_player());
	destruct(this_object());

     }
 else 
    message_vision("$N身上东西不够，看来是没有希望了。\n",this_player());
  return 1;
 }

