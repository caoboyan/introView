//
//  ViewController.m
//  BYIntrolView
//
//  Created by Boyan Cao on 16/3/29.
//  Copyright © 2016年 2015-293. All rights reserved.
//

#import "ViewController.h"
#import "BYIntrolView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 设置根控制器
    [self setUpRootVc];
    
    [BYIntrolView showIntrolViewFromView:self.view dataSource:self];

}

- (void)setUpRootVc {
    self.view.backgroundColor = [UIColor whiteColor];
    UILabel *label = [[UILabel alloc] init];
    label.text = @"rootViewController";
    label.font = [UIFont systemFontOfSize:22.0];
    [label sizeToFit];
    label.center = self.view.center;
    [self.view addSubview:label];
}

#pragma mark - <SCGuideViewDataSource>
- (NSArray *)contentImagesInIntroView:(BYIntrolView *)introView {
    return @[
             [UIImage imageNamed:@"guideView_1"],
             [UIImage imageNamed:@"guideView_2"],
             [UIImage imageNamed:@"guideView_3"]
             ];
}

- (UIImage *)backgroundImageInIntroView:(BYIntrolView *)introView {
    return [UIImage imageNamed:@"IntroBackground"];
}

- (NSArray *)titlesInIntroView:(BYIntrolView *)introView {
    return @[
             @"Page First",
             @"Page Second",
             @"Page Third",
             ];
}

- (NSArray *)descriptionTitlesInIntroView:(BYIntrolView *)introView {
    return @[
             @"Description for First Screen.",
             @"Description for Second Screen.",
             @"Description for Third Screen.",
             ];
}

- (UIButton *)doneButtonInIntroView:(BYIntrolView *)introView {
    UIButton *doneButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [doneButton setImage:[UIImage imageNamed:@"IntroStart"] forState:UIControlStateNormal];
    return doneButton;
}

@end
