// by tiandi 2008.5

#include <dbase.h>

int query_str()
{
	return (int)query("str") + (int)query("force_factor")/2
		+  query_temp("apply/strength") ;
}

int query_cor()
{
	return (int)query("cor") + (int)query("bellicosity") / 50
                +  query_temp("apply/courage") ;
}

int query_int()
{
	return (int)query("int")
                + query_temp("apply/intelligence");
}

int query_spi()
{
	return (int)query("spi")
                +  query_temp("apply/spirituality");
}

int query_cps()
{
	return (int)query("cps")
                +  query_temp("apply/composure");
}

int query_per()
{
	return (int)query("per")
                +  query_temp("apply/personality");
}

int query_con()
{
	return (int)query("con")
                +  query_temp("apply/constitution");
}

int query_kar()
{
	return (int)query("kar")
                +  query_temp("apply/karma");
}

int query_agi()
{
        return (int)query("agi")
                +  query_temp("apply/agility");
}
int query_dur()
{
        return (int)query("dur")
                +  query_temp("apply/durability") ;
}
int query_fle()
{
        return (int)query("fle")
                +  query_temp("apply/flexibility") ;
}
int query_tol()
{
        return (int)query("tol")
                +  query_temp("apply/tolerance");
}

