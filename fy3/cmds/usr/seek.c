//seek

#include <ansi.h>

int main(object me, string arg)
{
        int i, n;
        object ob;
        object *user;
        
//        if( !wizardp(me) ) return 0;
        if( !arg ) 
                return notify_fail("ÄãÒªÕÒÊ²Ã´ÈË£¿\n");
        
        write("Ä¿Ç°ÔÚÏßµÄÍæ¼ÒÖĞ£¬½Ğ "HIR+arg+NOR+" µÄÓĞ£º\n\n");
        user = users();
        for(i=0,n=0; i<sizeof(user); i++)
        if( user[i]->name()==arg )
        {
                write(user[i]->name()+"("+HIR+getuid(user[i])+NOR+")\n");
                n++;
        }
        if( n==0 ) write("Ä¿Ç°ÔÚÏßµÄÍæ¼Òµ±ÖĞÃ»ÓĞ½Ğ "+HIR+arg+NOR+" µÄ¡£\n");
        
        return 1;
}
int help (object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : seek [Íæ¼ÒÖĞÎÄÃû×Ö]
 
Õâ¸öÖ¸ÁîÈÃÄã²é¿´Íæ¼ÒµÄÖĞÎÄÃû×ÖÊÇÄÄ¸öÓ¢ÎÄÃû×Ö£
 
HELP
);
        return 1;
}

