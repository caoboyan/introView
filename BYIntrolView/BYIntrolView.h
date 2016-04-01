//
//  BYIntrolView.h
//  BYIntrolView
//
//  Created by Boyan Cao on 16/3/29.
//  Copyright © 2016年 2015-293. All rights reserved.
//

#import <UIKit/UIKit.h>
@class BYIntrolView;

//内容图片的展示模式
typedef enum{
    BYIntrolViewImageViewContentModeDefault,  //全屏显示图片
    BYIntrolViewImageViewContentModeCenter //居中显示图片
}BYIntrolViewImageViewContentMode;

//滑动消失引导图的模式
typedef enum
{
    BYIntrolViewDoneModeDefault,  //点击按钮结束引导图
    BYIntrolViewDoneModePanGesture, //拖拽结束引导图 (隐藏完成按钮)
    BYIntrolViewDoneModePanGestureAnimation  // 拖拽结束引导图 (隐藏完成按钮)
}BYIntrolViewDoneMode;

//引导图的数据元方法
@protocol BYIntrolViewDataSource <NSObject>

@required
/**
 *  返回每一页需显示的内容图
 */
- (NSArray *)contentImagesInIntroView:(BYIntrolView *)introView;

@optional
/** 返回背景图 */
- (UIImage *)backgroundImageInIntroView:(BYIntrolView *)introView;
/** 返回每一页需显示的标题*/
- (NSArray *)titlesInIntroView:(BYIntrolView *)introView;
/** 返回每一页需显示的子标题*/
- (NSArray *)descriptionTitlesInIntroView:(BYIntrolView *)introView;
/** 返回完成按钮 */
- (UIButton *)doneButtonInIntroView:(BYIntrolView *)introView;

/** 返回pageControl在纵坐标上的位置（SCIntroViewDoneMode为SCIntroViewDoneModeDefault时默认为0.8，其他默认为0.95） */
- (CGFloat)pageControlLocationInIntroView:(BYIntrolView *)introView;
/** 返回完成按钮在纵坐标上的位置 */
- (CGFloat)doneButtonLocationInIntroView:(BYIntrolView *)introView;


@end

@interface BYIntrolView : UIView

@property (nonatomic, weak) id<BYIntrolViewDataSource> dataSource;
/** 内容图片展示模式 */
@property (nonatomic, assign) BYIntrolViewImageViewContentMode introViewContentImageMode;
/** 移除Intro的模式 */
@property (nonatomic, assign) BYIntrolViewDoneMode introViewDoneMode;
/** 翻页指示器，默认hidden为YES */
@property (nonatomic, strong) UIPageControl *introViewPageControl;

/**
 *  快速展示introView，默认全屏展示图片和点击按钮的方式结束Intro
 *
 *  @param fromView          （必须）展示在哪个view之上
 *  @param dataSource        （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 */
+ (void)showIntrolViewFromView:(UIView *)fromView dataSource:(id)dataSource;

/**
 *  快速展示introView，默认点击按钮的方式结束Intro，按钮可用数据源方法返回
 *
 *  @param fromView                  （必须）展示在哪个view之上
 *  @param dataSource                （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 *  @param introViewContentImageMode （可选）内容图片的展示形式 （如为空，默认为全屏显示）
 */
+ (void)showIntrolViewFromView:(UIView *)fromView dataSource:(id)dataSource introViewContentImageMode:(BYIntrolViewImageViewContentMode)introViewContentImageMode;

/**
 *  快速展示introView，默认为全屏展示图片
 *
 *  @param fromView                  （必须）展示在哪个view之上
 *  @param dataSource                （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 *  @param introViewDoneMode         （可选）结束IntroView的方式 （默认为点击按钮结束）
 */
+ (void)showIntrolViewFromView:(UIView *)fromView dataSource:(id)dataSource introViewDoneMode:(BYIntrolViewDoneMode)introViewDoneMode;

/**
 *  快速展示introView
 *
 *  @param fromView                  （必须）展示在哪个view之上
 *  @param dataSource                （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 *  @param introViewContentImageMode （可选）内容图片的展示形式 （如为空，默认为全屏显示）
 *  @param introViewDoneMode         （可选）结束IntroView的方式 （默认为点击按钮结束）
 */
+ (void)showIntrolViewFromView:(UIView *)fromView dataSource:(id)dataSource introViewContentImageMode:(BYIntrolViewImageViewContentMode)introViewContentImageMode introViewDoneMode:(BYIntrolViewDoneMode)introViewDoneMode;

/**
 *  初始化一个IntroView，如不指定contentImageMode和doneMode，默认为全屏展示图片和点击按钮的方式结束Intro
 *
 *  @param frame             （必须）
 *  @param dataSource        （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 */
- (instancetype)initWithFrame:(CGRect)frame dataSource:(id)dataSource;

/**
 *  初始化一个IntroView，如不指定doneMode，默认为点击按钮的方式结束Intro
 *
 *  @param frame             （必须）
 *  @param contentImageMode  （可选）内容图片的展示形式 （如为空，默认为全屏显示）
 *  @param dataSource        （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 */
- (instancetype)initWithFrame:(CGRect)frame introViewContentImageMode:(BYIntrolViewImageViewContentMode)introViewContentImageMode dataSource:(id)dataSource;

/**
 *  初始化一个IntroView，如不指定contentImageMode和doneMode，默认为全屏展示图片
 *
 *  @param frame             （必须）
 *  @param doneMode          （可选）结束IntroView的方式 （如为空，默认为点击按钮结束）
 *  @param dataSource        （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 */
- (instancetype)initWithFrame:(CGRect)frame introViewDoneMode:(BYIntrolViewDoneMode)introViewDoneMode dataSource:(id)dataSource;

/**
 *  初始化一个IntroView
 *
 *  @param frame             （必须）
 *  @param contentImageMode  （可选）内容图片的展示形式 （如为空，默认为全屏显示）
 *  @param doneMode          （可选）结束IntroView的方式 （默认为点击按钮结束）
 *  @param dataSource        （必须）IntroView的数据源（背景图，背景色，内容图，标题等）
 */
- (instancetype)initWithFrame:(CGRect)frame introViewContentImageMode:(BYIntrolViewImageViewContentMode)introViewContentImageMode introViewDoneMode:(BYIntrolViewDoneMode)introViewDoneMode dataSource:(id)dataSource;

@end
