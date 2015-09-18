#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

/*
 * Following are defined in "RedBoxSettings.c" for all kiosk combined
 *   NUM_USERS 
 *   RENT_RATE_PS    
 *   RETURN_RATE_PS 
 *
*/

#include "RedBoxSettings.c"

// Comment this to disable new services
#define RB_ENABLE_NEW_SVC

#ifdef RB_ENABLE_NEW_SVC
#define RB_NUM_SERVICES 15
#else
#define RB_NUM_SERVICES 5
#endif

#define RB_KIOSK_PING_ID 0
#define RB_RENT_SERVICE_ID 1
#define RB_RETURN_SERVICE_ID 2
#define RB_FAILURE_RENT_SERVICE_ID 3
#define RB_OFFLINE_RENT_SERVICE_ID 4
#define RB_UNPLAYABLE_ID 5
#define RB_KIOSK_ANALYTICS_ID 6
#define RB_DISCOUNT_VALIDATION_ID 7
#define RB_GETCUST_CREDIT_ID 8
#define RB_RENT_OPTIN_ID 9
#define RB_DISC_ACTION_ID 10
#define RB_EMAIL_CONFIRM_ID 11
#define RB_PICK_UP_ID 12
#define RB_GIFTCARD_ID 13
#define RB_GC_PICKUP_ID 14
/*
Following variables need to be added in capture file
nsl_decl_var(LastPingTSVar);
nsl_decl_var(LastRentalTSVar);
nsl_decl_var(LastReturnTSVar);
nsl_decl_var(PageIdBeforePingVar);
*/


static int KioskDebug = 0;
static char KioskIdForDebug[64];
static char KioskId[64];

static char *tsToStr(int ts)
{
static char tsStr[64];

  if(ts == -1)
    ts = ns_get_ms_stamp();
  int ms = ts%1000;

  sprintf(tsStr, "%02d:%02d:%02d.%03d", (ts/1000)/3600, ((ts/1000)%3600)/60, ((ts/1000)%3600)%60, ms);
  return(tsStr);
}


//Will take the KisokId from NS
static void set_kiosk_id_for_debug()
{

  if(KioskDebug == 0)
  {
    KioskDebug = 1;
    strcpy(KioskIdForDebug, ns_eval_string("{KioskIdVar}"));
    #ifdef NS_DEBUG_ON
    fprintf(stderr, "%s - Info: KioskId for debug = %s\n", tsToStr(-1), KioskIdForDebug);
    #endif
  }  
}

// will check the KioskId should not be null
static int isKioskSetForDebug()
{
  if(strcmp(KioskIdForDebug, ns_eval_string("{KioskIdVar}")) == 0)
    return 1;
  return 0;
}


// All the getTS function fetches the last timestamp value in milli-seconds (relative to start of test) and setTS function saves it to NS variable
static unsigned long getLastPingTS()
{
  return((unsigned long)ns_get_int_val("LastPingTSVar"));  
}
static void setLastPingTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastPingTSVar", ts);  
}

static unsigned long getLastRentalTS()
{
  return((unsigned long)ns_get_int_val("LastRentalTSVar"));
}
static void setLastRentalTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastRentalTSVar", ts);
}

static unsigned long getLastReturnTS()
{
  return((unsigned long)ns_get_int_val("LastReturnTSVar"));
}
static void setLastReturnTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastReturnTSVar", ts);
}

static unsigned long getLastUnplayableTS()
{
  return((unsigned long)ns_get_int_val("LastUnplayableTSVar"));
}
static void setLastUnplayableTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastUnplayableTSVar", ts);
}

static unsigned long getLastKioskAnalyticsTS()
{
  return((unsigned long)ns_get_int_val("LastKioskAnalyticsTSVar"));
}
static void setLastKioskAnalyticsTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastKioskAnalyticsTSVar", ts);
}

static unsigned long getLastDiscountValidationTS()
{
  return((unsigned long)ns_get_int_val("LastDiscountValidationTSVar"));
}
static void setLastDiscountValidationTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastDiscountValidationTSVar", ts);
}

static unsigned long getLastFailureRentalTS()
{
  return((unsigned long)ns_get_int_val("LastFailureRentalTSVar"));
}
static void setLastFailureRentalTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastFailureRentalTSVar", ts);
}

static unsigned long getLastOfflineRentalTS()
{
  return((unsigned long)ns_get_int_val("LastOfflineRentalTSVar"));
}
static void setLastOfflineRentalTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastOfflineRentalTSVar", ts);
}

static unsigned long getLastGetCustCreditTS()
{
  return((unsigned long)ns_get_int_val("LastGetCustCreditTSVar"));
}
static void setLastGetCustCreditTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastGetCustCreditTSVar", ts);
}

static unsigned long getLastOptInRentalTS()
{
  return((unsigned long)ns_get_int_val("LastOptInRentalTSVar"));
}
static void setLastOptInRentalTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastOptInRentalTSVar", ts);
}

static unsigned long getLastGCRentalTS()
{
  return((unsigned long)ns_get_int_val("LastGCRentalTSVar"));
}
static void setLastGCRentalTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastGCRentalTSVar", ts);
}

static unsigned long getLastDiscActionTS()
{
  return((unsigned long)ns_get_int_val("LastDiscActionTSVar"));
}
static void setLastDiscActionTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastDiscActionTSVar", ts);
}

static unsigned long getLastEmailConfirmTS()
{
  return((unsigned long)ns_get_int_val("LastEmailConfirmTSVar"));
}
static void setLastEmailConfirmTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastEmailConfirmTSVar", ts);
}

static unsigned long getLastPickUpValidationTS()
{
  return((unsigned long)ns_get_int_val("LastPickUpValidationTSVar"));
}
static void setLastPickUpValidationTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastPickUpValidationTSVar", ts);
}

static unsigned long getLastGCPickUpValidationTS()
{
  return((unsigned long)ns_get_int_val("LastGCPickUpValidationTSVar"));
}
static void setLastGCPickUpValidationTS()
{
  unsigned long ts = ns_get_ms_stamp();
  ns_set_int_val("LastGCPickUpValidationTSVar", ts);
}

// it gets the previous PageId and serviceid (credit,discount,optin,DiscAction) Before Ping and set it to NS variable
static int getPageIdBeforePing()
{
  return(ns_get_int_val("PageIdBeforePingVar"));
}
static void setPageIdBeforePing(int pgId)
{
  ns_set_int_val("PageIdBeforePingVar", pgId);
}

static int getServiceIdBeforePing()
{
  return(ns_get_int_val("ServiceIdBeforePingVar"));
}
static void setServiceIdBeforePing(int ServiceID)
{
  ns_set_int_val("ServiceIdBeforePingVar", ServiceID);
}


// Calculate the min and max value for the random interval according to the service id called
static unsigned int getRandomInterval(int id, unsigned int interval, char *name)
{
  unsigned int min;
  unsigned int max;

  if ((id == RB_KIOSK_PING_ID) | (id == RB_RETURN_SERVICE_ID))
  {
    min = (int )(0.6*(double) interval);
    max = (int )(1.4*(double) interval);
  }
  else if (id == RB_RENT_SERVICE_ID)
  {
    min = (int )(0*(double) interval);
    max = (int )(2.0*(double) interval);
  }
  else if ((id == RB_GETCUST_CREDIT_ID) | (id == RB_RENT_OPTIN_ID))
  {
    min = (int )(0*(double) interval);
    max = (int )(10.0*(double) interval);
  }
  else if (id == RB_DISCOUNT_VALIDATION_ID)
  {
    min = (int )(0*(double) interval);
    max = (int )(10.5*(double) interval);
  }
  else if ((id == RB_DISC_ACTION_ID) | (id == RB_EMAIL_CONFIRM_ID) | (id == RB_GIFTCARD_ID))
  {
    min = (int )(0*(double) interval);
    max = (int )(16.0*(double) interval);
  }
  else if (id == RB_PICK_UP_ID)
  {
    min = (int )(0*(double) interval);
    max = (int )(15.0*(double) interval);
  }
 else
  {
    min = (int )(0*(double) interval);
    max = (int )(17.0*(double) interval);
  }

  unsigned int ranInterval = (unsigned int) ns_get_random_number_int(min, max);
  
  #ifdef NS_DEBUG_ON
  if(isKioskSetForDebug())
    fprintf(stderr, "%s - Info: KioksId = %s, getRandomInterval() for %s. Interval = %u, min = %d, max = %d, random interval = %d\n",tsToStr(-1), KioskIdForDebug, name, interval, min, max, ranInterval);
  #endif
  return(ranInterval);
}

// Think time between DiscountValidation and Rent message
static int getThinkTimeForRent()
{
  int pg_think_time;
  pg_think_time = 5000;
  return pg_think_time;
}

//Think time between Rent and KioskOptin
static int getThinkTimeForOptIn()
{
  int pg_think_time;
  pg_think_time = 5000;
  return pg_think_time;
}

// Think time between authorize or optIn and reconcile message
static int getThinkTimeForReconcile()
{
  int pg_think_time;
  pg_think_time = 5000; 
  return pg_think_time;
}

// Think time between PickUpValidation and PickUp
static int getThinkTimeForPickUp()
{
  int pg_think_time;
  pg_think_time = 5000; 
  return pg_think_time;
}

// This is for return service for unPlayable
static int getThinkTimeForReturnService2()
{
   int pg_think_time;
   pg_think_time = 5000; // 30 to 60 second random
   return pg_think_time;
}


/*
  Authorize -> Reconcile -> Ping
  Authorize -> Ping -> Reconcile
  Authorize -> Reconcile -> Return -> Ping
  Authorize -> Ping -> Reconcile -> Return -> Ping
  Authorize -> Ping -> Reconcile -> Ping -> Return -> Ping
  Return -> Ping
  Ping -> Ping
  many more based on offline and failure cases
*/


//Used for getting page id and time left for next service
typedef struct 
{
  int id; 			// Service Id
  unsigned int timeLeft; 	// Time left for next hit
  int  pageId;   		// Start Page id of the current service
  int  nextPageId; 		// Next page id if any or -1
  char serviceName[50];
} ServiceTime;

static ServiceTime serviceTime[RB_NUM_SERVICES];

// Used for starting service first time and for keeping interval
typedef struct
{
  unsigned int interval;
  double rate_ps;
  double cum_rate_ps; // User for selection of start service
} ServiceRate;

static double cum_rate_ps; 

static ServiceRate serviceRate[RB_NUM_SERVICES];

//if  RB_NUM_SERVICES 11 is used then if condition will execute and if RB_NUM_SERVICES 3 is used then else condition will execute and assign the services to array
static char serviceName[RB_NUM_SERVICES][100] = {
#ifdef RB_ENABLE_NEW_SVC
"KioskPing", "RentService", "ReturnService", "AuthorizeFailure", "ReconcileService", "UnplayableReturnService", "KioskAnalytics", "DiscountValidationService", "GetCustCredit", "RentService", "DiscActionService", "EmailConfirmation", "PickUpValidation", "RentService", "PickUpValidation"
#else
"KioskPing", "RentService", "ReturnService", "AuthorizeFailure", "ReconcileService" 
#endif
};

// Used when new RB services are enabled
#ifdef RB_ENABLE_NEW_SVC
static int serviceStartPageId[RB_NUM_SERVICES] = {KioskPing, RentService, ReturnService, AuthorizeFailure, ReconcileService, UnplayableReturnService, KioskAnalytics, DiscountValidationService , GetCustCredit, RentService, DiscActionService, EmailConfirmation, PickUpValidation, RentService, PickUpValidation};
#else
static int serviceStartPageId[RB_NUM_SERVICES] = {KioskPing, RentService, ReturnService, AuthorizeFailure, ReconcileService};
#endif

//Used to set the interval and rate per sec for each call 
static void setServiceRate(int id , double rate_ps)
{
unsigned int interval;
  if(rate_ps == 0){
    interval = 0;
  #ifdef NS_DEBUG_ON
  fprintf(stderr, " Service '%s;Rate is zero....so setting interval zero\n", serviceName[id]);
  #endif
  }
  else { 
    interval = (((double )NUM_USERS) * ((double )1000.0))/rate_ps; // millisecs
  }
  serviceRate[id].rate_ps = rate_ps;  
  serviceRate[id].interval = interval; 
  #ifdef NS_DEBUG_ON 
  fprintf(stderr, "%s - Info: Service '%s; - Rate_ps is %lf, interval is %u\n", (char*)__FUNCTION__, serviceName[id], rate_ps , interval );
  #endif
}

// Used to calculate the cumulative service rate 
static void setCumServiceRate()
{
 cum_rate_ps = 0;
 int i;
 for(i = 0; i < RB_NUM_SERVICES; i++){
   cum_rate_ps = cum_rate_ps + serviceRate[i].rate_ps;
   serviceRate[i].cum_rate_ps = cum_rate_ps;
 }
}
  
// For sorting of service time array by increasing order of time left
int compTime(const void *a, const void *b)
{
  if(((ServiceTime *)a)->timeLeft == 0xFFFFFFFF)
    return 1; // Return some positive number

  if(((ServiceTime *)a)->timeLeft < ((ServiceTime *)b)->timeLeft)
    return -1;
  else if(((ServiceTime *)a)->timeLeft > ((ServiceTime *)b)->timeLeft)
    return 1;
  else
    return 0;
}


static int setTimeLeft(int id, unsigned long curTS, unsigned long lastTS, int pageId, int nextPageId)
{
  unsigned int interval, timeElasped, timeLeft;
  //Time Left is setting very long so that it will never hit the servie
  if(serviceRate[id].interval == 0)
    timeLeft = 0xFFFFFFFF; // set max possible value
  else
  {
    interval =  getRandomInterval(id, serviceRate[id].interval, serviceName[id]);
    if(curTS >= lastTS)
      timeElasped = (unsigned int)(curTS - lastTS);
    else
    {
	#ifdef NS_DEBUG_ON
	fprintf(stderr, "Error: curTS is less than lastTS. KioskId = %s\n", KioskId);
	#endif
      timeElasped = 0;
    }

    if(interval >= timeElasped)
      timeLeft = interval - timeElasped;
    else
      timeLeft = 0;

    if(timeLeft >= 0x7FFFFFFF) 
    {
	#ifdef NS_DEBUG_ON
        fprintf(stderr, "Error: Time left is -ve. KioskId = %s\n", KioskId);
	#endif
      timeLeft = 0;
    }
  }
  serviceTime[id].id = id;
  serviceTime[id].timeLeft = timeLeft;
  serviceTime[id].pageId = pageId;
  serviceTime[id].nextPageId = nextPageId;
  strcpy(serviceTime[id].serviceName, serviceName[id]);
  #ifdef NS_DEBUG_ON
  if(isKioskSetForDebug())
    fprintf(stderr, "Info: Setting time left for %s, timeLeft = %u, pageId = %d,  nextPageId = %d, KioskId = %s\n", serviceName[id], timeLeft, pageId, nextPageId, KioskId);
  #endif
  return 0;
}

//Give the number of sevices with minimum same time left
static int getNumServiceWithMinSameTime()
{
  int numSameTime = 1; // Number of service with same time left
  int i;
  for( i = 0; i < (RB_NUM_SERVICES - 1); i++)
  {
    #ifdef NS_DEBUG_ON
    if(isKioskSetForDebug())
     fprintf(stderr, "Info: timeLeft[%d] = %u, KioskId = %s\n", i, serviceTime[i].timeLeft, KioskId);
    #endif
    if(serviceTime[i].timeLeft == serviceTime[i + 1].timeLeft)
      numSameTime++;
    else
      break;
  }
  #ifdef NS_DEBUG_ON
  if(isKioskSetForDebug())
    fprintf(stderr, "Info: Number of serices with min time left = %d, timeLeft = %u, KioskId = %s\n", numSameTime, serviceTime[0].timeLeft, KioskId);
  #endif
  return(numSameTime);
}

// Check if ping time left is less, then overide next page to ping
// Also saves the diff of time left of the page and ping in PgThinkTimeVar
static int getTTForNextPgOfAService(long curTS, int pg_think_time, int *nextPageId, char *name)
{
int save_pg_think_time = pg_think_time;

  if(serviceTime[RB_KIOSK_PING_ID].timeLeft <= pg_think_time)
  {
    // Save diff of time as page think time for return service 2
    ns_set_int_val("PgThinkTimeVar", pg_think_time - serviceTime[RB_KIOSK_PING_ID].timeLeft);
    pg_think_time = serviceTime[RB_KIOSK_PING_ID].timeLeft;
    *nextPageId = KioskPing;
   #ifdef NS_DEBUG_ON
    if(isKioskSetForDebug())
      fprintf(stderr, "%s - Info: KiosId = %s, timeLeftForPing (%u) is less than time left (%d) for the next page of service %s. So forcing ping.\n", tsToStr(curTS), KioskId, serviceTime[RB_KIOSK_PING_ID].timeLeft, save_pg_think_time, name);
   #endif
  }
  return(pg_think_time);
}

//It checks which service(Credit/Discount/Basic/OptIn) is called and return the Discount value correspondingly
static int  setupScriptForService(int id)
{
  ns_set_int_val("ServiceIdVar", id);

  switch(id)
  {
    case RB_GETCUST_CREDIT_ID:
      ns_save_string( "null", "DiscountCode");
      ns_save_string( "0", "DiscountValue");
      ns_save_string( "false", "ScriptStatus");
      break;
    case RB_DISCOUNT_VALIDATION_ID:
        ns_save_string( "\"DVDONME\"", "DiscountCode");
        ns_save_string( "false", "ScriptStatus");
      break;
    case RB_RENT_SERVICE_ID:
        ns_save_string( "false", "ScriptStatus");
        ns_save_string( "null", "DiscountCode");
        ns_save_string( "0", "DiscountValue");
      break;
    case RB_OFFLINE_RENT_SERVICE_ID:
      ns_save_string( "null", "RefNumVar");				// In case of offline mode, we need to send null in reference number
      ns_save_string( "true", "ScriptStatus");				// In case of offline mode, we need to send offline status to true
      break;
    case RB_RENT_OPTIN_ID:
      ns_save_string( "null", "DiscountCode");
      ns_save_string( "0", "DiscountValue");
      ns_save_string( "false", "ScriptStatus");
      break;
    case RB_GIFTCARD_ID:
      ns_save_string( "null", "DiscountCode");
      ns_save_string( "0", "DiscountValue");
      ns_save_string( "false", "ScriptStatus");
      break;

    default:
      break;
  }
  return(0);
}

// Select the next page id and the think time    
int selectStartService()
{

 // Set to -1 otherwise it will have 0 value which is for rent service
 setPageIdBeforePing(-1); 

 int rand_num = ns_get_random_number_int(0, (int )cum_rate_ps);
 int id;
 for(id = 0; id <= RB_NUM_SERVICES; id++)
 {
  if(serviceRate[id].interval == 0){
   #ifdef NS_DEBUG_ON
    fprintf(stderr, "Interval is %d,so continue loop \n", serviceRate[id].interval);
   #endif
    continue;
  }
  else if(rand_num <= serviceRate[id].cum_rate_ps)
  {
      break; 
  } 
 
}
 #ifdef NS_DEBUG_ON
 fprintf(stderr, "Info: First service is '%s'\n", serviceName[id]); 
 #endif
 setupScriptForService(id);

 return(serviceStartPageId[id]);
 
} 
 
 
// Selects one of the service which has minimum time left
static int selectService(long curTS, int *nextPageId)
{
unsigned int pg_think_time;

  // Sort service time array by timeleft in ascedning order. Note - Once sorting is done, we cannot index this arry using service idx
  qsort(serviceTime, RB_NUM_SERVICES, sizeof(ServiceTime), compTime);
  
  // Find out how many services have same min time left
  int numSameTime = getNumServiceWithMinSameTime();
    
  // Select one of these services randomly
  int selIdx = ns_get_random_number_int(0, (numSameTime - 1));
  pg_think_time = serviceTime[selIdx].timeLeft;
  *nextPageId = serviceTime[selIdx].pageId;

  setupScriptForService(serviceTime[selIdx].id);
  #ifdef NS_DEBUG_ON
  if(isKioskSetForDebug())
    fprintf(stderr, "%s - Info: selectService() - Selected %s. nextPageId = %d, pg_think_time = %u, KioskId = %s\n", tsToStr(curTS), serviceTime[selIdx].serviceName, *nextPageId, pg_think_time, KioskId);
  #endif
  return(pg_think_time);
}
    
//Gets the next page id and page think time    
static int getNextPageAndThinkTime(char *curPageName, int curPageId, double *pg_think_time_out)
{
  int nextPageId;
  unsigned int pg_think_time;
  int curServiceId = ns_get_int_val("ServiceIdVar"); 

  unsigned long curTS = ns_get_ms_stamp();
  
  set_kiosk_id_for_debug(); // This will set KioskId once for debug log
  strcpy(KioskId, ns_eval_string("{KioskIdVar}"));

  setTimeLeft(RB_KIOSK_PING_ID, curTS, getLastPingTS(), KioskPing, -1);
  setTimeLeft(RB_RENT_SERVICE_ID, curTS, getLastRentalTS(), RentService, ReconcileService);
  setTimeLeft(RB_RETURN_SERVICE_ID, curTS, getLastReturnTS(), ReturnService, -1);
  setTimeLeft(RB_FAILURE_RENT_SERVICE_ID, curTS, getLastFailureRentalTS(), AuthorizeFailure, ReconcileFailure);
  setTimeLeft(RB_OFFLINE_RENT_SERVICE_ID, curTS, getLastOfflineRentalTS(), ReconcileService, -1);

#ifdef RB_ENABLE_NEW_SVC
  setTimeLeft(RB_UNPLAYABLE_ID, curTS, getLastUnplayableTS(), UnplayableReturnService, ReturnService2);
  setTimeLeft(RB_KIOSK_ANALYTICS_ID, curTS, getLastKioskAnalyticsTS(), KioskAnalytics, -1);
  setTimeLeft(RB_DISCOUNT_VALIDATION_ID, curTS, getLastDiscountValidationTS(), DiscountValidationService, RentService);
  setTimeLeft(RB_GETCUST_CREDIT_ID, curTS, getLastGetCustCreditTS(), GetCustCredit, RentService);
  setTimeLeft(RB_RENT_OPTIN_ID, curTS, getLastOptInRentalTS(), RentService, KioskOptInService);
  setTimeLeft(RB_DISC_ACTION_ID, curTS, getLastDiscActionTS(), DiscActionService, -1);
  setTimeLeft(RB_EMAIL_CONFIRM_ID, curTS, getLastEmailConfirmTS(), EmailConfirmation, -1);
  setTimeLeft(RB_PICK_UP_ID, curTS, getLastPickUpValidationTS(), PickUpValidation, PickUp);
  setTimeLeft(RB_GIFTCARD_ID, curTS, getLastGCRentalTS(), RentService, ReconcileService);
  setTimeLeft(RB_GC_PICKUP_ID, curTS, getLastGCPickUpValidationTS(), PickUpValidation, PickUp);
#endif

  int curPageStatus = ns_get_page_status(); // 0 - Success else fail
  if(curPageStatus != 0) 
  {
    #ifdef NS_DEBUG_ON
    fprintf(stderr, "%s - Warning: %s page failed. KioskId = %s\n", tsToStr(curTS),curPageName, KioskId);
    #endif
    curPageId = -1; // Set to -1 so avoid going to Reconcile after ping
  }
 
  // TODO: Can we elimiate this?
  if((curPageId == GetCustCredit) && (curPageStatus == 0))
  {
    nextPageId = RentService;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForRent(), &nextPageId, "GetCustCredit");
  }
  else if((curPageId == DiscountValidationService) && (curPageStatus == 0))
  {
    nextPageId = RentService;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForRent(), &nextPageId, "DiscountValidationService");
  }
  // if current page is RentService, next page can be Reconcile or OptIn
  else if((curPageId == RentService) && (curPageStatus == 0) && (curServiceId == RB_RENT_OPTIN_ID))
  {
   nextPageId = KioskOptInService;
   pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForOptIn(), &nextPageId, "RentService");
   }
  else if((curPageId == RentService) && (curPageStatus == 0) && (curServiceId != RB_RENT_OPTIN_ID))
   {
    nextPageId = ReconcileService;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForReconcile(), &nextPageId, "RentService");
   }
  else if((curPageId == KioskOptInService) && (curPageStatus == 0) && (curServiceId == RB_RENT_OPTIN_ID))
  {
    nextPageId = ReconcileService;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForReconcile(), &nextPageId, "KioskOptInService");
  }
  // If current page is UnplayableReturnService then next can either be ReturnService2 or Ping
  else if ((curPageId == AuthorizeFailure) && (curPageStatus == 0))
  {
    nextPageId = ReconcileFailure;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForReconcile(), &nextPageId, "AuthorizeFailure");
  }
  else if ((curPageId == UnplayableReturnService) && (curPageStatus == 0))
  {
    nextPageId = ReturnService2;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForReturnService2(), &nextPageId, "UnplayableReturnService");
  }
  else if ((curPageId == PickUpValidation) && (curPageStatus == 0))
  {
    nextPageId = PickUp;
    pg_think_time = getTTForNextPgOfAService(curTS, getThinkTimeForPickUp(), &nextPageId, "PickUpValidation");
  }
  else if(curPageId == KioskPing) 
  // Check if due to ping, we did not do ReconcileService last time
  { 
    if((getPageIdBeforePing() == GetCustCredit) && (getServiceIdBeforePing() == RB_GETCUST_CREDIT_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = RentService;
    }
    else if((getPageIdBeforePing() == DiscountValidationService) && (getServiceIdBeforePing() == RB_DISCOUNT_VALIDATION_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = RentService;
    }
    else if((getPageIdBeforePing() == RentService) && (getServiceIdBeforePing() != RB_RENT_OPTIN_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = ReconcileService;
    }
    else if((getPageIdBeforePing() == RentService) && (getServiceIdBeforePing() == RB_RENT_OPTIN_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = KioskOptInService;
    }
    else if((getPageIdBeforePing() == KioskOptInService) && (getServiceIdBeforePing() == RB_RENT_OPTIN_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = ReconcileService;
    }
    else if((getPageIdBeforePing() == UnplayableReturnService) && (getServiceIdBeforePing() == RB_UNPLAYABLE_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = ReturnService2;
    }
    else if((getPageIdBeforePing() == AuthorizeFailure) && (getServiceIdBeforePing() == RB_FAILURE_RENT_SERVICE_ID))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = ReconcileFailure;
    }
    else if((getPageIdBeforePing() == PickUpValidation) && ((getServiceIdBeforePing() == RB_PICK_UP_ID) || (getServiceIdBeforePing() == RB_GC_PICKUP_ID)))
    {
      pg_think_time = ns_get_int_val("PgThinkTimeVar");
      nextPageId = PickUp;
    }
    else
      pg_think_time = selectService(curTS, &nextPageId); 
  }
  else 
  {  
    pg_think_time = selectService(curTS, &nextPageId); 
  }


  if(nextPageId == KioskPing)
  {
    setPageIdBeforePing(curPageId);
    setServiceIdBeforePing(curServiceId);
  }
  // ns_set_pg_think_time(pg_think_time);
  *pg_think_time_out = (double )pg_think_time/1000.0; // page think time in C Type is passed in seconds

   #ifdef NS_DEBUG_ON
if(isKioskSetForDebug())
 fprintf(stderr, "%s - Info: getNextPageAndThinkTime() - KioskId = %s , pg_think_time = %u, nextPageId = %d\n",  tsToStr(curTS), KioskId, pg_think_time, nextPageId);
#endif  
return(nextPageId);
}



void init_interval()
{

  double rent_rate_ps;
  double rent_promo_ps;
  double rent_credit_ps;
  double rent_optin_ps;
  double rent_giftcard_ps;
 
  rent_rate_ps = TRAN_RATE_PS / (((RENT_ONLY * RENT_ONEITEM)/10000.0) + 
		((RENT_ONLY * RENT_TWOITEM * 2 )/10000.0) + 
		((RENT_PURCHASE * RENT_PURCHASE_PUR_ONLY )/10000.0) +
		((RENT_PURCHASE * RENT_PURCHASE_PUR_RENT * 2)/10000.0)) ;
  
  #ifdef NS_DEBUG_ON
  fprintf(stderr,"rent_rate_ps = %lf\n", rent_rate_ps); 
  #endif
  
  rent_credit_ps = GETCREDIT_RATE_PS / (((RENT_ONLY * RENT_ONEITEM)/10000.0) +
                ((RENT_ONLY * RENT_TWOITEM * 2 )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_ONLY )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_RENT * 2)/10000.0)) ;
  
  #ifdef NS_DEBUG_ON
  fprintf(stderr,"rent_credit_ps = %lf\n", rent_credit_ps); 
  #endif

  rent_optin_ps = KIOSK_OPTIN_RATE_PS / (((RENT_ONLY * RENT_ONEITEM)/10000.0) +
                ((RENT_ONLY * RENT_TWOITEM * 2 )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_ONLY )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_RENT * 2)/10000.0)) ;

  #ifdef NS_DEBUG_ON
  fprintf(stderr,"rent_optin_ps = %lf\n", rent_optin_ps);
  #endif
   
  rent_giftcard_ps = GIFTCARD_RATE_PS / (((RENT_ONLY * RENT_ONEITEM)/10000.0) +
                ((RENT_ONLY * RENT_TWOITEM * 2 )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_ONLY )/10000.0) +
                ((RENT_PURCHASE * RENT_PURCHASE_PUR_RENT * 2)/10000.0)) ;

  #ifdef NS_DEBUG_ON
  fprintf(stderr,"rent_giftcard_ps = %lf\n", rent_giftcard_ps);
  #endif
  memset(serviceRate, 0, sizeof(serviceRate));

  rent_promo_ps = (DISCOUNTVALIDATION_RATE_PS * rent_rate_ps)/100;
  rent_rate_ps = rent_rate_ps - rent_promo_ps;

  setServiceRate(RB_RENT_SERVICE_ID, rent_rate_ps);
  setServiceRate(RB_RETURN_SERVICE_ID, RETURN_RATE_PS);
  setServiceRate(RB_KIOSK_PING_ID, PING_INTERVAL_PS);
  setServiceRate(RB_FAILURE_RENT_SERVICE_ID, RENTAL_FAILURE_RATE_PS);
  setServiceRate(RB_OFFLINE_RENT_SERVICE_ID, RENTAL_OFFLINE_RATE_PS);
  setServiceRate(RB_UNPLAYABLE_ID, UNPLAYABLE_RATE_PS);
  setServiceRate(RB_KIOSK_ANALYTICS_ID, KIOSKANALYTICS_RATE_PS);
  setServiceRate(RB_DISCOUNT_VALIDATION_ID, rent_promo_ps);
  setServiceRate(RB_GETCUST_CREDIT_ID, rent_credit_ps);
  setServiceRate(RB_RENT_OPTIN_ID, rent_optin_ps);
  setServiceRate(RB_DISC_ACTION_ID, DISC_ACTION_RATE_PS);
  setServiceRate(RB_EMAIL_CONFIRM_ID, EMAIL_CONFIRM_RATE_PS);
  setServiceRate(RB_PICK_UP_ID, PICK_UP_RATE_PS);
  setServiceRate(RB_GIFTCARD_ID, rent_giftcard_ps);
  setServiceRate(RB_GC_PICKUP_ID, GC_PICKUP_RATE_PS);
  setCumServiceRate();
}

