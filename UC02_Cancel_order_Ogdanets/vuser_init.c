vuser_init()
{
	web_reg_save_param("userSession",
                   "LB=name=\"userSession\" value=\"",
                   "RB=\"/>", LAST);
	
	web_url("webTours", 
		"URL=http://localhost:1080/webTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC02_TR01_Login");
	
	web_reg_find("Text=Welcome, <b>{Login}</b>, to the Web Tours reservation pages.",LAST);
	
	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=42", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_end_transaction("UC02_TR01_Login",LR_AUTO);
	
	lr_think_time(TNINKTIME);
	
	return 0;
}
