vuser_end()
{
	lr_start_transaction("UC01_TR07_Log_Out");

	//Add safety 
	web_reg_find("Text=Username",LAST);
	
	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t8.inf",
		"Mode=HTML",
		LAST);
	lr_end_transaction("UC01_TR07_Log_Out",LR_AUTO);
	return 0;
}
