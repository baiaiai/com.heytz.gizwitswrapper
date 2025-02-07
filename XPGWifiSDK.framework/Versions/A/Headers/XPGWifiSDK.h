//
//  XPGWifiSDK.h
//  XPGWifiSDK
//
//  Created by xpg on 14-7-8.
//  Copyright (c) 2014年 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <XPGWifiSDK/XPGWifiDevice.h>
#import <XPGWifiSDK/XPGWifiSSID.h>
#import <XPGWifiSDK/XPGWifiBinary.h>
#import <XPGWifiSDK/XPGWifiCentralControlDevice.h>
#import <XPGWifiSDK/XPGWifiSubDevice.h>
#import <XPGWifiSDK/XPGWifiGroup.h>

/**
 XPGWifiThirdAccountType枚举，描述SDK支持的第三方账号类型
 */
typedef NS_ENUM (NSInteger, XPGWifiThirdAccountType)
{
    /**
     百度账号
     */
    XPGWifiThirdAccountTypeBAIDU = 0,

    /**
     新浪账号
     */
    XPGWifiThirdAccountTypeSINA,
    
    /**
     腾讯账号
     */
    XPGWifiThirdAccountTypeQQ,
};

/**
 XPGWifiLogLevel枚举，描述SDK提供的日志级别
 */
typedef NS_ENUM (NSInteger, XPGWifiLogLevel)
{
    /**
     错误日志
     */
    XPGWifiLogLevelError = 0,

    /**
     错误和警告日志
     */
    XPGWifiLogLevelWarning,

    /**
     所有日志
     */
    XPGWifiLogLevelAll,
};

/**
 XPGWifiErrorCode枚举，描述SDK提供的所有错误码定义。
 
 其中，9000以上的错误码是OpenAPI返回的，定义请参考：
    http://site.gizwits.com/zh-cn/document/openplatform/i_05_openapi/#_3
 
 */
typedef NS_ENUM (NSInteger, XPGWifiErrorCode)
{
    /**
     无错误
     */
    XPGWifiError_NONE = 0,

    /**
     一般错误
     */
    XPGWifiError_GENERAL = -1,
    
    /**
     写入数据的操作未执行
     */
    XPGWifiError_NOT_IMPLEMENTED = -2,
    
    /**
     读取或写入数据时，数据长度不在 0-65535 的范围
     */
    XPGWifiError_PACKET_DATALEN = -4,

    /**
     错误的连接 ID
     */
    XPGWifiError_CONNECTION_ID = -5,
    
    /**
     连接已关闭
     */
    XPGWifiError_CONNECTION_CLOSED = -7,
    
    /**
     数据包的校验和不正确
     */
    XPGWifiError_PACKET_CHECKSUM = -8,

    /**
     控制设备时，发现该设备没有登录过
     */
    XPGWifiError_LOGIN_FAIL = -10,
    
    /**
     执行 MQTT 相关操作时出错
     */
    XPGWifiError_MQTT_FAIL = -12,
    
    /**
     发现小循环设备或者配置 AirLink 时，收到的数据包不能正确解析相关的内容
     */
    XPGWifiError_DISCOVERY_MISMATCH = -13,
    
    /**
     调用 setsockopt() 失败
     */
    XPGWifiError_SET_SOCK_OPT = -14,
    
    /**
     线程创建失败
     */
    XPGWifiError_THREAD_CREATE = -15,
    
    /**
     建立太多的连接，导致连接池满了。最大允许建立 255 个 TCP 连接
     */
    XPGWifiError_CONNECTION_POOL_FULLED = -17,
    
    /**
     大循环操作时，使用了空的 Client ID
     */
    XPGWifiError_NULL_CLIENT_ID = -18,
    
    /**
     连接出现错误
     */
    XPGWifiError_CONNECTION_ERROR = -19,
    
    /**
     传入了错误的参数
     */
    XPGWifiError_INVALID_PARAM = -20,
    
    /**
     连接超时。默认超时 1 分钟
     */
    XPGWifiError_CONNECT_TIMEOUT = -21,
    
    /**
     数据包版本号错误
     */
    XPGWifiError_INVALID_VERSION = -22,
    
    /**
     不能分配内存
     */
    XPGWifiError_INSUFFIENT_MEM = -23,
    
    /**
     当前线程在使用中
     */
    XPGWifiError_THREAD_BUSY = -24,
    
    /**
     HTTP 操作失败
     */
    XPGWifiError_HTTP_FAIL = -25,
    
    /**
     获取 Passcode 失败
     */
    XPGWifiError_GET_PASSCODE_FAIL = -26,
    
    /**
     获取 DNS 失败
     */
    XPGWifiError_DNS_FAILED = -27,

    /**
     配置 on-boarding 时，手机连接的 SSID 与配置设备的 SSID 不一致
     */
    XPGWifiError_CONFIGURE_SSID_NOT_MATCHED = -39,
    
    /**
     配置 on-boarding 超时
     */
    XPGWifiError_CONFIGURE_TIMEOUT = -40,
    
    /**
     配置 on-boarding 时，发送失败
     */
    XPGWifiError_CONFIGURE_SENDFAILED = -41,
    
    /**
     配置错误，执行 Soft-AP 方法但不在 Soft-AP 模式
     */
    XPGWifiError_NOT_IN_SOFTAPMODE = -42,
    
    /**
     接收到了不可识别的数据
     */
    XPGWifiError_UNRECOGNIZED_DATA = -43,
    
    /**
     不能连接，无法获取到网关
     */
    XPGWifiError_CONNECTION_NO_GATEWAY = -44,
    
    /**
     连接被拒绝
     */
    XPGWifiError_CONNECTION_REFUSED = -45,
};

/**
 XPGWifiLoginErrorCode枚举，描述设备登录错误码
 */
typedef NS_ENUM (NSInteger, XPGWifiLoginErrorCode)
{
    /**
     已获取控制权限
     */
    XPGWifiLoginError_CONTROL_ENABLED = 0,

    /**
     已登录但不能控制
     */
    XPGWifiLoginError_LOGINED,
    
    /**
     登录失败
     */
    XPGWifiLoginError_FAILED,
};

/**
 XPGConfigureMode枚举，描述SDK支持的设备配置方式
 */
typedef NS_ENUM (NSInteger, XPGConfigureMode)
{
    /**
     SoftAP配置模式
     */
    XPGWifiSDKSoftAPMode = 1,

    /**
     AirLink配置模式
     */
    XPGWifiSDKAirLinkMode = 2,
};

/**
 XPGWifiGAgentType枚举，描述SDK支持的Wifi模组类型
 */
typedef NS_ENUM (NSInteger, XPGWifiGAgentType)
{
    /**
     MXCHIP模组（庆科）
     */
    XPGWifiGAgentTypeMXCHIP = 0,
    
    /**
     HF模组（汉枫）
     */
    XPGWifiGAgentTypeHF = 1,

    //RTK模组（RealTek）
    XPGWifiGAgentTypeRTK = 2,
};

typedef enum _tagXPGCloudService
{
    XPG_PRODUCTION = 0,
    XPG_QA = 1,
    XPG_DEVELOPMENT = 2,
    XPG_TENCENT = 3,
}XPGCloudService;

@class XPGWifiSDK;

/**
 XPGWifiSDKDelegate是XPGWifiSDK类的委托协议，为APP开发者处理设备配置和发现、设备分组、用户登录和注册提供委托函数。
 */
@protocol XPGWifiSDKDelegate <NSObject>
@optional

/**
 在 Soft-AP 模式下获取 SSID 列表的回调接口，返回设备 Soft AP 模式下的 SSID 列表
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param ssidList 为若干 XPGWifiSSID 实例组成的 SSID 信号列表
 @param result 获取结果 成功或失败。如果获取失败，ssidList为nil
 @see 触发函数：[XPGWifiSDK getSSIDList]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didGetSSIDList:(NSArray *)ssidList result:(int)result;

/**
 设备配置的回调接口，返回设备配置的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param device 已配置成功的设备
 @param result 配置结果 成功或失败。如果配置失败，device为nil
 @see 触发函数：[XPGWifiSDK setDeviceWifi:key:mode:softAPSSIDPrefix:timeout:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didSetDeviceWifi:(XPGWifiDevice *)device result:(int)result;

/**
 获取设备列表的回调接口，返回发现设备的结果。当有新设备上线时，也会触发此接口的回调
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param deviceList 为 XPGWifiDevice 实例组成的数组
 @param result 0为成功，其他失败。如果失败，deviceList为nil
 @see 触发函数：[XPGWifiSDK getBoundDevicesWithUid:token:specialProductKeys:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didDiscovered:(NSArray *)deviceList result:(int)result;

/**
 获取分组列表的回调接口，返回分组列表
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param groupList 为 XPGWifiGroup 实例组成的数组
 @param result 0为成功，其他失败。如果失败，groupList为nil
 @see 触发函数：[XPGWifiSDK getGroupsWithUid:token:specialProductKeys:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didGetGroups:(NSArray *)groupList result:(int)result;

/**
 回调接口，自定义CRC算法，下发V3数据协议的设备控制命令会触发此回调接口
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param data 需要计算的二进制数据
 @return 返回计算出的CRC值
 @see 触发函数：[XPGWifiDevice write:]
 */
- (NSUInteger)XPGWifiSDK:(XPGWifiSDK *)wifiSDK needsCalculateCRC:(NSData *)data;

/**
 获取设备配置文件的回调接口，返回从服务器下载到的配置
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param product 下载的设备配置文件内容
 @param result 下载的结果：-25=网络故障，-1=服务器返回的数据错误，0=成功。自动下载的情况下，下载的结果：1=不更新
 @see 触发函数：[XPGWifiSDK updateDeviceFromServer:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didUpdateProduct:(NSString *)product result:(int)result;

/**
 获取手机验证码的回调接口，返回向指定手机发送验证码的请求结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK requestSendVerifyCode:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didRequestSendVerifyCode:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 用户注册的回调接口，返回注册用户的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @param uid 注册成功后得到的uid（不成功则为nil）
 @param token 注册成功后得到的token（不成功则为nil）
 @see 触发函数：[XPGWifiSDK registerUser:password:]、[XPGWifiSDK registerUserByEmail:password:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didRegisterUser:(NSNumber *)error errorMessage:(NSString *)errorMessage uid:(NSString *)uid token:(NSString *)token;

/**
 用户登录的回调接口，返回用户登录的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @param uid 登录成功后得到的uid（不成功则为nil）
 @param token 登录成功后得到的token（不成功则为nil）
 @see 触发函数：[XPGWifiSDK userLoginAnonymous]、[XPGWifiSDK userLoginWithUserName:password:]、[XPGWifiSDK userLoginWithThirdAccountType:uid:token:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didUserLogin:(NSNumber *)error errorMessage:(NSString *)errorMessage uid:(NSString *)uid token:(NSString *)token;

/**
 用户注销的回调接口，返回用户注销的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK userLogout:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didUserLogout:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 匿名用户转换的回调接口，返回匿名用户转换为普通用户或手机用户的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK transAnonymousUserToNormalUser:passcode:]、[XPGWifiSDK transAnonymousUserToPhoneUser:phone:password:code:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didTransUser:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 修改用户密码的回调接口，返回修改用户密码结果（对应changeUserPassword、changeUserPasswordByCode）
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK changeUserPassword:oldPassword:newPassword:]、[XPGWifiSDK changeUserPasswordByCode:code:newpassword:]、[XPGWifiSDK changeUserPasswordByEmail:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didChangeUserPassword:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 修改用户邮箱的回调接口，返回修改用户邮箱的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK changeUserEmail:email:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didChangeUserEmail:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 修改用户手机号的回调接口，修改用户手机号结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK changeUserPhone:phone:code:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didChangeUserPhone:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 设备绑定的回调接口，返回设备绑定的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param did 设备 did
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK bindDeviceWithUid:token:did:passCode:remark:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didBindDevice:(NSString *)did error:(NSNumber *)error errorMessage:(NSString *)errorMessage;

/**
 设备解绑的回调接口，返回设备解绑的结果
 @param wifiSDK 为回调的 XPGWifiSDK 单例
 @param did 设备 did
 @param error 0为成功，其他失败
 @param errorMessage 错误信息（无错误则为nil）
 @see 触发函数：[XPGWifiSDK unbindDeviceWithUid:token:did:passCode:]
 */
- (void)XPGWifiSDK:(XPGWifiSDK *)wifiSDK didUnbindDevice:(NSString *)did error:(NSNumber *)error errorMessage:(NSString *)errorMessage;

@end

/**
 XPGWifiSDK类为APP开发者提供设备配置和发现、设备分组、用户登录和注册函数
 */
@interface XPGWifiSDK : NSObject

/**
 获取 XPGWifiSDK 单例的实例
 @return XPGWifiSDK 单例
 */
+ (XPGWifiSDK *)sharedInstance;

/**
 初始化 SDK
 @param appID 在机智云申请到的应用标识。在 site.gizwits.com 中，每个注册的设备在“产品信息”中，都能够查到对应的 appID。
 @note 请务必最先调用此接口，为后续的接口调用做准备
 */
+ (void)startWithAppID:(NSString *)appID;

/**
 使用委托获取对应事件。XPGWifiSDK 对应的回调接口在 XPGWifiSDKDelegate 定义，需要用到哪个接口，实现对应的回调即可
 */
@property (nonatomic, assign) id <XPGWifiSDKDelegate>delegate;

/**
 读取SDK版本号
 @return XPGWifiSDK 的版本号
 */
- (NSString*)getVersion;

/**
 设置Log级别、Log文件路径、Log内二进制输出级别
 @param logLevel 日志级别，默认 =XPGWifiLogLevelAll
 @see XPGWifiLogLevel
 @param logFile 日志文件保存在/Documents下，如果指定Nil，则不输出到文件。默认不输出到文件
 @param bPrintDataInDebug 是否打印详细的二进制数据。默认 不打印
 @note 此接口仅在[XPGWifiSDK sharedInstance]后设置有效
 */
+ (void)setLogLevel:(XPGWifiLogLevel)logLevel logFile:(NSString *)logFile printDataLevel:(BOOL)bPrintDataInDebug;

/**
 注册识别 Soft AP 模式的规则
 @param ssidPrefix 识别SSID的前缀
 @note 在载入配置文件之前配置有效，默认为nil
 @deprecated 此接口已废弃，请使用替代接口：[setDeviceWifi:key:mode:softAPSSIDPrefix:timeout:]
 */
+ (void)registerSSIDs:(NSString *)ssidPrefix, ... NS_REQUIRES_NIL_TERMINATION DEPRECATED_ATTRIBUTE;

#ifdef SWIFT
+ (void)registerSSID:(NSString *)ssid;
+ (void)clearSSIDs;
#endif

#ifdef __INTERNAL_SUPPORT_SWITCH_SERVICE_AND_LOG_CACHE__
/*
 设置服务地址切换，用于切换云端的调试环境和发布环境
 @param specialService XPGCloudService类型：0=生产环境 1=测试环境 2=开发环境 3=腾讯云
 @note 默认生产环境
 */
+ (void)setSwitchService:(int)specialService;
#endif

#ifdef __INTERNAL_SUPPORT_SWITCH_SERVICE_AND_LOG_CACHE__
/*
 设置SDK缓存日志条数
 @param count 范围：0-10000
 */
+ (void)setLogCacheCount:(NSInteger)count;

/*
 获取日志文本
 @result 返回日志数组
 */
+ (NSArray *)getLogList;
#endif

#ifdef __INTERNAL_TESTING_API__
#define CURRENT_SERVICE @"CurrentService"
#define OPENAPI_SERVICE @"OpenAPI"
#define CONFIG_SERVICE @"Configure"
#define M2M_SERVICE @"m2mService"

/*
 获取当前云端环境域名
 @param deviceDID 指定设备的Did，用于获取该设备连接的M2M域名
 @result 服务名称字典 {key, value} = {CURRENT_SERVICE:当前环境}、{OPENAPI_SERVICE:业务域名}、{CONFIG_SERVICE:配置文件服务器域名}、{M2M_SERVICE:M2M域名}
 */
+ (NSDictionary*)getUsingService:(NSString*)deviceDID;
#endif

/**
 获取设备配置文件
 @param productKey 设备唯一标识符
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didUpdateProduct:result:]
 */
+ (void)updateDeviceFromServer:(NSString *)productKey;

/**
 配置设备连接路由的方法
 @param ssid 需要配置到路由的SSID名
 @param key 需要配置到路由的密码
 @param mode 配置方式
 @see XPGConfigureMode
 @param timeout 设备配置的超时时间 SDK默认执行的最小超时时间为30秒
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didSetDeviceWifi:result:]
 @deprecated 此接口已废弃，请使用替代接口：[setDeviceWifi:key:mode:softAPSSIDPrefix:timeout:]
 */
- (void)setDeviceWifi:(NSString*)ssid
                  key:(NSString*)key
                 mode:(XPGConfigureMode)mode
              timeout:(int)timeout DEPRECATED_ATTRIBUTE;

/**
 配置设备连接路由的方法
 @param ssid 需要配置到路由的SSID名
 @param key 需要配置到路由的密码
 @param mode 配置方式
 @see XPGConfigureMode
 @param softAPSSIDPrefix SoftAPMode模式下SoftAP的SSID前缀或全名（XPGWifiSDK以此判断手机当前是否连上了SoftAP，AirLink配置时该参数无意义，传nil即可）
 @param timeout 配置的超时时间 SDK默认执行的最小超时时间为30秒
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didSetDeviceWifi:result:]
 @deprecated 此接口已废弃，请使用替代接口：[setDeviceWifi:key:mode:softAPSSIDPrefix:timeout:wifiGAgentType:]
 */
- (void)setDeviceWifi:(NSString*)ssid
                  key:(NSString*)key
                 mode:(XPGConfigureMode)mode
     softAPSSIDPrefix:(NSString*)softAPSSIDPrefix
              timeout:(int)timeout DEPRECATED_ATTRIBUTE;

/**
 配置设备连接路由的方法
 @param ssid 需要配置到路由的SSID名
 @param key 需要配置到路由的密码
 @param mode 配置方式
 @see XPGConfigureMode
 @param softAPSSIDPrefix SoftAPMode模式下SoftAP的SSID前缀或全名（XPGWifiSDK以此判断手机当前是否连上了SoftAP，AirLink配置时该参数无意义，传nil即可）
 @param timeout 配置的超时时间 SDK默认执行的最小超时时间为30秒
 @param types 配置的wifi模组类型列表，存放NSNumber对象，SDK默认同时发送庆科和汉枫模组配置包；SoftAPMode模式下该参数无意义。types为nil，SDK按照默认处理。如果只想配置庆科模组，types中请加入@XPGWifiGAgentTypeMXCHIP类；如果只想配置汉枫模组，types中请加入@XPGWifiGAgentTypeHF；如果希望多种模组配置包同时传，可以把对应类型都加入到types中。XPGWifiGAgentType枚举类型定义SDK支持的所有模组类型。
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didSetDeviceWifi:result:]
 */
- (void)setDeviceWifi:(NSString*)ssid
                  key:(NSString*)key
                 mode:(XPGConfigureMode)mode
     softAPSSIDPrefix:(NSString*)softAPSSIDPrefix
              timeout:(int)timeout
       wifiGAgentType:(NSArray*)types;

/**
 在 Soft-AP 模式时，获得 SSID 列表。SSID列表通过异步回调方式返回
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didGetSSIDList:result:]
 */
- (void)getSSIDList;

/**
 请求向指定手机发送验证码
 @param phone 手机号
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didRequestSendVerifyCode:errorMessage:]
 */
- (void)requestSendVerifyCode:(NSString *)phone;

/**
 注册普通用户（通过用户名、密码注册）
 @param userName 注册用户名
 @param password 注册密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didRegisterUser:errorMessage:uid:token:]
 */
- (void)registerUser:(NSString *)userName password:(NSString *)password;

/**
 注册手机号用户（通过手机号、密码跟校验码注册）
 @param phone 注册手机号
 @param password 注册密码
 @param code 注册验证码（通过requestSendVerifyCode方法触发指定手机号接收短信内的验证码）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didRegisterUser:errorMessage:uid:token:]
 */
- (void)registerUserByPhoneAndCode:(NSString *)phone password:(NSString *)password code:(NSString *)code;

/**
 注册邮箱用户（通过邮箱、密码注册）
 @param email 注册邮箱
 @param password 注册密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didRegisterUser:errorMessage:uid:token:]
 */
- (void)registerUserByEmail:(NSString *)email password:(NSString *)password;

/**
 匿名用户登录（匿名方式）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didUserLogin:errorMessage:uid:token:]
 */
- (void)userLoginAnonymous;

/**
 用户登录（用户名、密码方式）
 @param szUserName 注册得到的用户名
 @param szPassword 注册得到的密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didUserLogin:errorMessage:uid:token:]
 */
- (void)userLoginWithUserName:(NSString *)szUserName password:(NSString *)szPassword;

/**
 第三方账号登录（第三方接口登录方式）
 @param szThirdAccountType 第三方账户的类型
 @see XPGWifiThirdAccountType
 @param szUid 第三方账户的uid
 @param szToken 第三方账户的token
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didUserLogin:errorMessage:uid:token:]
 */
- (void)userLoginWithThirdAccountType:(XPGWifiThirdAccountType)szThirdAccountType uid:(NSString *)szUid token:(NSString *)szToken;

/**
 用户注销
 @param uid 登录成功后得到的uid
 */
- (void)userLogout:(NSString *)uid;

/**
 匿名用户转换普通用户
 @param token 从登录或注册的账号得到的 token
 @param userName 待转换用户的用户名
 @param password 待转换用户的密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didTransUser:errorMessage:]
 */
- (void)transAnonymousUserToNormalUser:(NSString *)token userName:(NSString *)userName password:(NSString *)password;

/**
 匿名用户转换手机用户
 @param token 从登录或注册的账号得到的 token
 @param phone 待转换用户的手机号
 @param password 待转换用户的密码
 @param code 手机验证码（通过requestSendVerifyCode方法触发指定手机号接收短信内的验证码）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didTransUser:errorMessage:]
 */
- (void)transAnonymousUserToPhoneUser:(NSString *)token phone:(NSString *)phone password:(NSString *)password code:(NSString *)code;

/**
 修改用户密码
 @param token 登录成功后得到的 token
 @param oldPassword 之前的老密码
 @param newPassword 需要修改的新密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didChangeUserPassword:errorMessage:]
 */
- (void)changeUserPassword:(NSString *)token oldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword;

/**
 手机用户通过短信验证码重置密码
 @param phone 手机号
 @param code 短信验证码
 @param newPassword 设置新密码
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didChangeUserPassword:errorMessage:]
 */
- (void)changeUserPasswordByCode:(NSString *)phone code:(NSString *)code newPassword:(NSString *)newPassword;

/**
 手机用户通过邮箱重置密码
 @param email 邮箱地址
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didChangeUserPassword:errorMessage:]
 */
- (void)changeUserPasswordByEmail:(NSString *)email;

/**
 修改用户邮箱
 @param token 登录成功后得到的token
 @param email 指定需要修改成的邮箱地址
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didChangeUserEmail:errorMessage:]
 */
- (void)changeUserEmail:(NSString *)token email:(NSString *)email;

/**
 修改用户手机号
 @param token 登录成功后得到的token
 @param phone 指定需要修改成的手机号
 @param code 指定需要修改成的手机号收到验证码（通过requestSendVerifyCode方法触发指定手机号接收短信内的验证码）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didChangeUserPhone:errorMessage:]
 */
- (void)changeUserPhone:(NSString *)token phone:(NSString *)phone code:(NSString *)code;

/**
 绑定设备到服务器
 @param token 登录成功后得到的token
 @param uid 登录成功后得到的uid
 @param did 待绑定设备的did
 @param passCode 待绑定设备的passCode（能得到就传，得不到可传Nil，SDK会内部尝试获取PassCode）
 @param remark 待绑定设备的别名，无别名可传nil
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didBindDevice:error:errorMessage:]
 */
- (void)bindDeviceWithUid:(NSString *)uid token:(NSString *)token did:(NSString *)did passCode:(NSString *)passCode remark:(NSString*)remark;

/**
 从服务器解绑设备
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param did 待解绑设备的did
 @param passCode 待解绑设备的passCode（能得到就传，得不到可传Nil，SDK会内部尝试获取PassCode）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didUnbindDevice:error:errorMessage:]
 */
- (void)unbindDeviceWithUid:(NSString *)uid token:(NSString *)token did:(NSString *)did passCode:(NSString *)passCode;

/**
 获取绑定设备及本地设备列表
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param specialProductKey 指定待筛选设备的产品标识（获取或搜索到未指定设备产品标识的设备将其过滤，指定Nil则不过滤）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didDiscovered:result:]
 */
- (void)getBoundDevicesWithUid:(NSString *)uid token:(NSString *)token specialProductKeys:(NSString *)specialProductKey, ... NS_REQUIRES_NIL_TERMINATION;

/**
 获取分组列表
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param specialProductKey 指定待筛选的组类型标识（获取到未指定类型标识的组将其过滤，指定Nil则不过滤）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didGetGroups:result:]
 */
- (void)getGroupsWithUid:(NSString *)uid token:(NSString *)token specialProductKeys:(NSString *)specialProductKey, ... NS_REQUIRES_NIL_TERMINATION;

/**
 新建设备分组
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param productKey 指定组类型标识
 @param groupName 指定组名称
 @param specialDevices 指定加入组内的设备（成员为字典，依赖键值sdid（子设备标识码）、did（父设备标识码），暂不加入设备则传空）
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didGetGroups:result:]
 */
- (void)addGroup:(NSString *)uid
           token:(NSString *)token
      productKey:(NSString *)productKey
       groupName:(NSString *)groupName
  specialDevices:(NSArray *)specialDevices;

/**
 删除设备分组
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param gid 指定组ID
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didGetGroups:result:]
 */
- (void)removeGroup:(NSString *)uid token:(NSString *)token gid:(NSString *)gid;

/**
 编辑设备分组
 @param uid 登录成功后得到的uid
 @param token 登录成功后得到的token
 @param gid 指定组ID
 @param groupName 指定组昵称
 @param specialDevices 编辑组内的设备（成员为字典，依赖键值sdid（子设备标识码）、did（父设备标识码））
 @see 对应的回调接口：[XPGWifiSDKDelegate XPGWifiSDK:didGetGroups:result:]
 */
- (void)editGroup:(NSString *)uid
            token:(NSString *)token
              gid:(NSString *)gid
        groupName:(NSString*)groupName
   specialDevices:(NSArray *)specialDevices;

#ifdef SWIFT
- (void)getBoundDevice:(NSString *)uid token:(NSString *)token;
- (void)EnableProductFilter:(BOOL)isEnable;
- (void)RegisterProductKey:(NSString *)productKey;
- (void)ClearProductKey;
#endif

@end
