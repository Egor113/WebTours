vuser_end()
{
	lr_start_transaction("UC02_TR04_Logout");

	web_url("SignOff Button", 
		"URL={Host}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_TR04_Logout",LR_AUTO);
	return 0;
}
