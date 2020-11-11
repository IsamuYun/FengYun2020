#include <vote.h>
#include <ansi.h>
#define IP_VOTE_NUM	3  //定义一个ip能投票的数量
#define COL_PERIOD 300
inherit F_DBASE;
void check_vote(string whowhat);
int get_value(string what);
void create()
{
        seteuid( ROOT_UID );
}
int add_vote(object me, string what, string who)
{
	int flag = 0;
	string ip_num;
	        string *ips;
	        int i;  
				string *ids;
			    int j;  

	ip_num = (string)query_ip_number(me);

        if(!query(who+"/"+what))
        {
	        set(who+"/"+what, ({ ip_num }));
	        set(who+"/"+what+"_time", time());
	        call_out("check_vote", COL_PERIOD, who+"/"+what);
	        return 1;
        }
        
        if(sizeof(query(who+"/"+what)) < get_value(what))
        {
			if(sizeof(query_temp(ip_num)) >= IP_VOTE_NUM)
			{
				return 0;	        	
			}
			
	        ips = query(who+"/"+what);
	        for(i=0;i<sizeof(ips);i++)
	        {
	        	if(ips[i] == ip_num)
	        	{
	        		flag = 1;	
	        	}
			    ids = query_temp(ips[i]);
	            for(j=0;j<sizeof(ids);j++)
	            {
	            	if(ids[j] == me->query("id"))
	                {
	                	return 0;	
	                }
	            }
	        }
	        
	        add_temp(ip_num, ({ me->query("id") }));
	        
	        if(flag==0)
	        {
	        	add(who+"/"+what, ({ ip_num }));
	        }
	        
	        if(sizeof(query(who+"/"+what)) < get_value(what))
	        {
	                return sizeof(query(who+"/"+what));
	        }
	        else
	        {
	        	ips = query(who+"/"+what);
		        for(i=0;i<sizeof(query(who+"/"+what));i++)
		        {
		        	delete_temp(ips[i]);
		        }	        	
	        	delete(who+"/"+what);
	        }
	        return i+1;
		}
}

void check_vote(string whowhat)
{
        string who,what;
        string msg;
        string *ips;
	    int i;  
        
        if(sscanf(whowhat,"%s/%s",who,what) !=2 ) return;
        
        if(query(whowhat))
        {
	        msg = HIW "【投票表决】：由于票数不够，关于对"+who+"实行"+what+"的表决现在取消。\n" NOR;        
	        message("system",msg,users());  
        
	        ips = query(who+"/"+what);
		    for(i=0;i<sizeof(query(who+"/"+what));i++)
		    {
		    	delete_temp(ips[i]);
		    }	        	
        	delete(who+"/"+what);
        }
        return;
}

int get_value(string what)
{
switch(what) {
        case "right": return (int) right_no;
        case "noright": return (int) noright_no;
        case "kickout": return (int) kickout_no;
        case "robot": return (int) robot_no;
        case "block": return (int) block_no;
        case "noblock": return (int) noblock_no;
        case "ban": return (int) ban_no;
        case "off": return (int) off_no;
        case "on": return (int) on_no;
        case "imprison" : return (int) imprison_no;
        case "redis" : return (int) sizeof(users())/2 + 1;
        default : return 0;
                }

}
