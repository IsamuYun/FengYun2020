//欢乐英雄
//updated by lion@hero
//backup.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;
       object* inv;
        int i, cur_time;
        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("你不是经由正常连线进入，不能储存。\n");
       cur_time=time();    
       if( cur_time - me->query("last_backup") < 900 )
       return notify_fail("离你上一次备份还不到15分钟!\n");
        if((int)link_ob->save()&&(int)me->save()){
        tell_object(me,"档案储存完毕。\n");
        if((int)me->backup()&&(int)link_ob->backup()){
        me->set("last_backup", cur_time);
        me->set("last_save", cur_time);
        tell_object(me,"个人数据备份成功.\n");
       //自造物品备份。
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); ++i)  {       
       if(inv[i]->query("owner") == getuid(me)&&
       (inv[i]->query_backup_file())){
       inv[i]->unequip();  
       if( (int)inv[i]->backup() ) 
       tell_object(me,"自造物品备份成功.\n");
            }
       
       }
     }   
     else tell_object(me,"备份失败!\n");
        return 1;
        } else {
                tell_object(me,"储存失败。\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
指令格式：backup

备份您的数据，当您的档案遭受以外破坏时可以用备份数据来回复。
HELP
        );
        return 1;
}

