inherit ITEM;
void create()
{
        set_name("���Ʊ�����ͼ��", ({ "fengyun-map" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","
                     /AAAAAAAAAAAAAAAAA\  /AAAAAAAAAAA\  /AAAAAAAAAAAAAA/\/\_     
                  _/AAAAAAAAAAAAAAAAAAAA\/AAAAAAAAAAAAA\/AAAAAAAAAAAAAAAA_/\/\        
                 /AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA           
                  |~~~~|=|~~~~~||~~~~~|==|~~~~~~~~~~~~~|==|~~~~~||~~~~~|=|~~~~|
                  |____|=|_____||_____|==|_____________|==|_____||_____|=|____|
                  |mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm| 
                  |~~~~|=|~~~~~||~~~~~|==|~~~~~~~~~~~~~|==|~~~~~||~~~~~|=|~~~~|
                  |____|=|_____||_____|==|_____________|==|_____||_____|=|____|  
                  |wwwwwwwWWWWWWWWWWWWmmmmWWWWWWWWWWWWWmmmmWWWWWWWWWWWWwwwwwww|   
                   ~~|==||~~~~~~~~~~~~|==| |      ""   """"| |==|~~~~~~~~~~~~||==|~~ 
                     |==||   //       |==| |  o | o  | |==|   //       ||==|      
                     |==||============|==| |____|____| |==|============||==|         
             ############WWWWWWWWWWWWWW-=================-WWWWWWWWWWWWWW##############
           `````````````````````````` ======================```````````````````````````` 
     
        \n");
            }

   
}