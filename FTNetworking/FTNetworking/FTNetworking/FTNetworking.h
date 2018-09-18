//
//  FTNetworking.h
//  FTNetworking
//
//  Created by wolffy on 2018/9/17.
//  Copyright © 2018年 派博在线（北京）科技有限责任公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FTSessionRequest.h"

@interface FTNetworking : NSObject

#pragma mark - GET请求

/**
 发起GET请求，不带Header

 @param Host 主机地址
 @param completed 成功回调
 @param failed 失败回调
 */
+ (void)getWithHost:(NSString *)Host completion:(FTNetCompleteBlock)completed failed:(FTNetFailedBlock)failed;

@end
