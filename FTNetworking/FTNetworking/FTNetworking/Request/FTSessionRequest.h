//
//  FTSessionRequest.h
//  FTNetworking
//
//  Created by wolffy on 2018/9/17.
//  Copyright © 2018年 派博在线（北京）科技有限责任公司. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,FTRequestMethod){
    FTRequestMethodGet,
    FTRequestMethodPost,
    FTRequestMethodPut,
    FTRequestMethodDelete
};

/**
 定义请求成功回调block

 @param response 响应头
 @param responseData 响应体
 @param statusCode http状态码
 */
typedef void (^FTNetCompleteBlock) (NSURLResponse * _Nonnull response,NSData * _Nonnull responseData,NSInteger statusCode);

/**
 定义请求失败回调block

 @param response 响应头
 @param responseData 响应体
 @param statusCode http状态码
 */
typedef void (^FTNetFailedBlock) (NSURLResponse * _Nonnull response,NSData * _Nonnull responseData,NSInteger statusCode);

@interface FTSessionRequest : NSObject

#pragma mark - GET

/**
 GET请求

 @param host 主机地址
 @param headers 请求头
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)getWithHost:(NSString *)host headers:(NSDictionary *)headers completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

#pragma mark - POST

/**
 POST请求，不带文件

 @param host 主机地址
 @param headers 请求头
 @param parameters 请求体
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)postWithHost:(NSString *)host headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

/**
 POST请求，带文件
 
 @param host 主机地址
 @param headers 请求头
 @param parameters 请求体
 @param files key+file value，file会被base64处理，file为NSData类型
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)postWithHost:(NSString *)host headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters files:(NSDictionary *)files completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

#pragma mark - PUT

/**
 PUT请求，不带文件
 
 @param host 主机地址
 @param headers 请求头
 @param parameters 请求体
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)putWithHost :(NSString *)host headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

/**
 PUT请求，带文件
 
 @param host 主机地址
 @param headers 请求头
 @param parameters 请求体
 @param files key+file value，file会被base64处理,file为NSData类型
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)putWithHost :(NSString *)host headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters files:(NSDictionary *)files completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

#pragma mark - DELETE

/**
 DELETE请求
 
 @param host 主机地址
 @param headers 请求头
 @param completed 请求成功回调
 @param failed 请求失败回调
 */
- (void)deleteWithHost:(NSString *)host headers:(NSDictionary *)headers completed:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

@end
