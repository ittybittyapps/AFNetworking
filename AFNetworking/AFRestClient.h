// AFRestClient.h
//
// Copyright (c) 2011 Gowalla (http://gowalla.com/)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "AFJSONRequestOperation.h"

#import "NSMutableURLRequest+AFNetworking.h"
#import "NSString+AFNetworking.h"

@interface AFRestClient : NSObject {
@private
    NSURL *_baseURL;
    NSMutableDictionary *_defaultHeaders;
    NSOperationQueue *_operationQueue;
}

- (id)initWithBaseURL:(NSURL *)url;

- (NSString *)defaultValueForHeader:(NSString *)header;
- (void)setDefaultHeader:(NSString *)header value:(NSString *)value;
- (void)setAuthorizationHeaderWithUsername:(NSString *)username password:(NSString *)password;
- (void)setAuthorizationHeaderWithToken:(NSString *)token;
- (void)clearAuthorizationHeader;

- (NSMutableURLRequest *)requestWithMethod:(NSString *)method 
                                      path:(NSString *)path parameters:(NSDictionary *)parameters;

- (void)enqueueHTTPOperation:(AFHTTPRequestOperation *)operation;

- (void)enqueueHTTPOperationWithRequest:(NSURLRequest *)request 
                                success:(AFJSONRequestSuccessHandler)success 
                                failure:(AFJSONRequestFailureHandler)failure
                                onQueue:(dispatch_queue_t)queue;

- (void)cancelHTTPOperationsWithRequest:(NSURLRequest *)request;

- (void)cancelAllHTTPOperations;

- (void)getPath:(NSString *)path 
     parameters:(NSDictionary *)parameters 
        success:(AFJSONRequestSuccessHandler)success;

- (void)getPath:(NSString *)path 
     parameters:(NSDictionary *)parameters 
        success:(AFJSONRequestSuccessHandler)success 
        failure:(AFJSONRequestFailureHandler)failure;

- (void)postPath:(NSString *)path 
      parameters:(NSDictionary *)parameters 
         success:(AFJSONRequestSuccessHandler)success;

- (void)postPath:(NSString *)path 
      parameters:(NSDictionary *)parameters 
         success:(AFJSONRequestSuccessHandler)success 
         failure:(AFJSONRequestFailureHandler)failure;

- (void)putPath:(NSString *)path 
     parameters:(NSDictionary *)parameters 
        success:(AFJSONRequestSuccessHandler)success;

- (void)putPath:(NSString *)path 
     parameters:(NSDictionary *)parameters 
        success:(AFJSONRequestSuccessHandler)success 
        failure:(AFJSONRequestFailureHandler)failure;

- (void)deletePath:(NSString *)path 
        parameters:(NSDictionary *)parameters 
           success:(AFJSONRequestSuccessHandler)success;

- (void)deletePath:(NSString *)path 
        parameters:(NSDictionary *)parameters 
           success:(AFJSONRequestSuccessHandler)success 
           failure:(AFJSONRequestFailureHandler)failure;
@end
