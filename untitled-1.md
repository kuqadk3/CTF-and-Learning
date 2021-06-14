# Untitled

## Introduction

During my research into Javascript Engine \(V8\), I have created a tool to help you view recent V8 bugs on a single page. This is useful to analyze V8 vulnerabilities, detect different bug patterns or patch gapping. For patch gapping, there was also a case that developers pushed the regression test file before the patch was applied to Chrome \(see [Twitter 0day](https://twitter.com/r4j0x00/status/1381643526010597380)\)

## How It Works

The tool simply parsed all `regress-*` files under the directory and sub-directory of [/src/v8/test/mjsunit/](https://source.chromium.org/chromium/chromium/src/+/master:v8/test/mjsunit/)

From there, I used `git log` to retrieve information related to the regress file.

```text
git log -1 --name-only /path/to/regress/file
```

Each regress will contain these information :

* [Chromium Bugs](https://bugs.chromium.org/p/chromium/issues) / [V8 Bugs](https://bugs.chromium.org/p/v8/issues)  
* [V8 Git](https://chromium.googlesource.com/v8/v8/+/master/test/mjsunit/)  
* [Chromium Code Search](https://cs.chromium.org/chromium/src/v8/test/mjsunit/)  
* [Chromium Code Review](https://chromium-review.googlesource.com)

The output of each regress will look like this

![Output](.gitbook/assets/image%20%28110%29.png)

Using this method, I have gathered a large set of PoCs/Regression tests with related information, ordered by committed time and divided by year, from 2016 to 2021. See [V8 Harvest](https://github.com/star-sg/V8Harvest).

## How To Use

Install following python3 lib

```text
python3 -m pip install GitPython
python3 -m pip install tqdm
```

Clone the V8 git repo to your local machine

```text
git clone https://github.com/v8/v8.git
```

Put **v8Harvest.py** in V8's folder and run it, output will be named **output.md**

![](.gitbook/assets/image%20%28113%29.png)

**Note: Big thank to Jacob for helping me with cleaning my clumsy code and porting it to python3**

