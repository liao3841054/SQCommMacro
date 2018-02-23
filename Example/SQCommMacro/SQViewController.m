//
//  SQViewController.m
//  SQCommMacro
//
//  Created by SQKB on 02/23/2018.
//  Copyright (c) 2018 SQKB. All rights reserved.
//

#import "SQViewController.h"
#import <SQCommMacro/SQAppInfoMacro.h>
#import <SQCommMacro/SQUtilMacro.h>

@interface SQViewController ()

@end

@implementation SQViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    BOOL result = IsEmpty(@"HHH");
    
    UIView *backView = [[UIView alloc] initWithFrame:kScreenRect];
    backView.backgroundColor = RGB(0, 122, 22);
    [self.view addSubview:backView];
    
    UIWindow *window = SQKeyWindow();
    CGFloat xx =  SQFloatPixelCeil(16.4);
    CGFloat xx1 =  SQFloatPixelFloor(16.4);
    
    
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
