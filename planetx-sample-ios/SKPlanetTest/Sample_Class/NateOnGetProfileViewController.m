//
//  NateOnGetProfileViewController.m
//  SKPOPSDKSample
//
//  Created by Lion User on 01/08/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "NateOnGetProfileViewController.h"
#import "Const.h"

#import "APIRequest.h"
#import "RequestBundle.h"

@interface NateOnGetProfileViewController ()

@end

@implementation NateOnGetProfileViewController

@synthesize myTextView;

APIRequest *api;
RequestBundle *reqBundle;


#define URL SERVER@"/nateon/profile"


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"Get NateOn Profile";
    
    reqBundle = [[RequestBundle alloc] init];
    api = [[APIRequest alloc] init];
}

- (void)viewDidUnload
{
    [myTextView release];
    myTextView = nil;
    
    [api release];
    api = nil;
    
    [reqBundle release];
    reqBundle = nil;
    
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}


- (void)clearResult {
    [myTextView setText:@""];
}

- (void) initRequestBundle
{
    NSMutableDictionary *param = [[NSMutableDictionary alloc] init];
    [param setValue:@"1" forKey:@"version"];
    
    reqBundle = [[RequestBundle alloc] init];
    [reqBundle setUrl:URL];
    
    // Private 테스트
    //[reqBundle setUrl:@"https://apis.skplanetx.com/cyworld/note/67324899/items?abstract=&count=&page=&profileThumb=&contentThumb=&filter=&version=1"];
    //[reqBundle setUrl:@"https://apis.skplanetx.com/cyworld/note/67324899/items"];
    
    [reqBundle setParameters:param];
    [reqBundle setHttpMethod:SKPopHttpMethodGET];
    [reqBundle setResponseType:SKPopContentTypeXML];
    [reqBundle setRequestType:SKPopContentTypeFORM];
    
    [param release];
    
    NSLog(@"reqBundle %@", reqBundle.url);
    
}

- (IBAction)requestSync:(id)sender {
    
    [self clearResult];
    
    [self initRequestBundle];
    
    ResponseMessage *result = nil;
    
    NSError *error = nil;
    NSLog(@"reqBundle %@", reqBundle.url);
    result = [api request:reqBundle error:&error];
    
    if ( error ) {
        [myTextView setText:[error localizedDescription]];
    } else {
        [myTextView setText:[NSString stringWithFormat:@"%@\n%@", result.statusCode, result.resultMessage]];
    }
    
    [result release];
}


- (IBAction)requestAsync:(id)sender {
    
    [self clearResult];
    
    [self initRequestBundle];
    
    [api setDelegate:self
            finished:@selector(apiRequestFinished:) 
              failed:@selector(apiRequestFailed:)];
    [api aSyncRequest:reqBundle];
    
}

#pragma mark - SKPOP SDK Delegate

-(void)apiRequestFinished:(NSDictionary *)result
{
    NSLog(@"apiRequestFinished : %@", result);
    [myTextView setText:[result valueForKey:SKPopASyncResultData]];
    [result release];
}

-(void)apiRequestFailed:(NSDictionary *)result
{
    NSLog(@"apiRequestFailed : %@", result);
    [myTextView setText:[result valueForKey:SKPopASyncResultMessage]];
    [result release];
}

@end