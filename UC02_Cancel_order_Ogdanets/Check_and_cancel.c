Check_and_cancel()
{
	int i;

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC02_TR02_Check");

	 web_reg_save_param("c_flightids",
	   "lb=<input type=\"hidden\" name=\"flightID\" value=\"", "rb=\"  />",
	   "ord=all",
	   LAST);
	
	 web_reg_save_param("c_cgifields",
	   "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
	   "rb=\"  />",
	   "ord=all",
	   LAST);
	
	web_url("welcome.pl", 
		"URL={Host}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_TR02_Check",LR_AUTO);
	
	/*
	Добавить в параметр c_buffer значение 1=on&
	
	Выражение "1=on&" означает, что будет осуществляться удаление
	1-го бронирования сверху, т.е. удаление того бронирования, напротив
	которого стоит галочка, в данном случае галочка стоит у checkbox1
	*/
	
	lr_param_sprintf("c_buffer", "1=on&");
	
	for (i=1;i<=atoi(lr_eval_string("{c_flightids_count}"));i++)
	 {
		 lr_param_sprintf("c_buffer", "%sflightID=%s&",
		   lr_eval_string("{c_buffer}"),
		   lr_paramarr_idx("c_flightids",
		   i));		
	}
	
		for (i=1;i<=atoi(lr_eval_string("{c_flightids_count}"));i++)
	 {
		
		 lr_param_sprintf("c_buffer",
		   "%s.cgifields=%s&",
		   lr_eval_string("{c_buffer}"),
		   lr_paramarr_idx("c_cgifields", i));
	}
	
	lr_save_string(lr_eval_string("{c_buffer}removeFlights.x=62&removeFlights.y=14"),
   "c_wcr");
	
	/*
	В параметр "c_wcr" складывается запрос на удаление бронирования из приложения
	Запрос формируется в следующем формате:
	1=on&flightID=ID1&flightID=ID2& ... &flightID=IDN&.cgifields=1&.cgifields=2& ... 
	&.cgifields=N&removeFlights.x=62&removeFlights.y=14
	*/
		
	lr_think_time(TNINKTIME);

	lr_start_transaction("UC02_TR03_Cancel");

	web_reg_find("Text=Itinerary",LAST);
	
	web_custom_request("itinerary.pl","Method=POST",
		"URL={Host}:{Port}/cgi-bin/itinerary.pl",
		"Body={c_wcr}",
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML",		
		LAST);

	lr_end_transaction("UC02_TR03_Cancel",LR_AUTO);

	lr_think_time(TNINKTIME);

	return 0;
}