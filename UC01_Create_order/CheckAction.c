CheckAction()
{

	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR06_Itenarary");

	web_reg_find("Text=Itinerary",LAST);
	
	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("UC01_TR06_Itenarary",LR_AUTO);

	lr_think_time(TNINKTIME);

	return 0;
}