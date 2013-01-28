/*
 * Constants.h
 */

static NSString *const SKPopHeaderAppKey = @"appKey";
static NSString *const SKPopHeaderAccessToken = @"access_token";
static NSString *const SKPopHeaderRefreshToken = @"refresh_token";

// OAUTH ONLY : STEP 1 AUTHORIZATION
static NSString *const SKPopOAuthClientID = @"client_id";
static NSString *const SKPopOAuthResponseType = @"response_type"; // VALUE : code
static NSString *const SKPopOAuthScope = @"scope";
static NSString *const SKPopOAuthRedirectURI = @"redirect_uri"; // VALUE :
// OAUTH ONLY : STEP 2 ACCESSTOKEN
static NSString *const SKPopOAuthClientSecret = @"client_secret";
static NSString *const SKPopOAuthCode = @"code"; // 인증 Endpoint에서 받은 
// Authorization code
static NSString *const SKPopOAuthGrantType = @"grant_type"; // VALUE : authorization_code

// OAUTH ONLY : REFRESH TOKEN
static NSString *const SKPopOAuthRefreshToken 	= @"refresh_token";

static NSString *const SKPopOAuthEndAccessToten 	= @"access_token";
static NSString *const SKPopOAuthEndRefreshToken 	= @"refresh_token";
static NSString *const SKPopOAuthEndExpiresIn 		= @"expires_in";
static NSString *const SKPopOAuthEndScope 			= @"scope";
static NSString *const SKPopOAuthEndExpiresSystem	= @"expires_systime";

// OAuth 인증서버
#define SKPopOAuthServer @"https://oneid.skplanetx.com"
//#define SKPopOAuthServer @"http://dev-oneid.skplanetx.com"
// OAuth STEP1 : 인증 Endpoint
#define SKPopOAuthAuthen SKPopOAuthServer@"/oauth/authorize"
// OAuth STEP2(1+2) : Access Token 발급 Endpoint
#define SKPopOAuthAccess SKPopOAuthServer@"/oauth/token" 



typedef enum {
    SKPopContentTypeXML
    , SKPopContentTypeJSON 
    , SKPopContentTypeFORM
    , SKPopContentTypeJS
    , SKPopContentTypeKML
    , SKPopContentTypeKMZ
    , SKPopContentTypeGEO
} SKPopContentType;

typedef enum {
    SKPopHttpMethodPUT
    , SKPopHttpMethodPOST
    , SKPopHttpMethodGET
    , SKPopHttpMethodDELETE
} SKPopHttpMethod;

static NSString *const SKPopError00001 = @"HttpMethod is null";
static NSString *const SKPopError00002 = @"Url is null or empty";
static NSString *const SKPopError00003 = @"ReturnType-value is wrong";
static NSString *const SKPopError00004 = @"ASynchronous Listener is null" ;
static NSString *const SKPopError00005 = @"Header infomation is null";     
static NSString *const SKPopError00006 = @"Application Key is null or empty";       
static NSString *const SKPopError00007 = @"Context is null."; 

// ASync 용
#define SKPopASyncResultCode @"RC"
#define SKPopASyncResultMessage @"RM"
#define SKPopASyncResultData @"RD"

@interface Constants : NSObject

+ (NSString *)getContentType:(SKPopContentType) type;

@end


// TODO FIXME 중요!! 무효화 루틴 상용 배포시 반드시 제거할것.!!!!!!!!!!
// SSL 인증 무효화 루틴 추가
@interface NSURLRequest (DummyInterface)
+ (BOOL)allowsAnyHTTPSCertificateForHost:(NSString*)host;
+ (void)setAllowsAnyHTTPSCertificate:(BOOL)allow forHost:(NSString*)host;
@end

/*
 * OAuthInfo.h
 */

@interface OAuthInfo : NSObject

@property (nonatomic, retain) NSString *appKey;
@property (nonatomic, retain) NSString *accessToken;
@property (nonatomic, retain) NSString *refreshToken;
@property (nonatomic, retain) NSString *expiresIn;
@property (nonatomic, retain) NSString *scope;
@property (nonatomic, retain) NSString *expiresSystime;

+(id)sharedInstance;
-(NSString *)getWholeInfo;

@end







