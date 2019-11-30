vuser_init()
{
	web_reg_save_param("userSession",
                   "LB=name=\"userSession\" value=\"",
                   "RB=\"/>", LAST);
	
	web_url("WebTours", 
		"URL={Host}:{Port}/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_start_transaction("UC01_TR01_Login");

	web_reg_find("Text=Welcome, <b>{Login}</b>, to the Web Tours reservation pages.",LAST);

	web_submit_data("login.pl", 
		"Action={Host}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=61", ENDITEM, 
		"Name=login.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);
	lr_think_time(TNINKTIME);
	return 0;
}
