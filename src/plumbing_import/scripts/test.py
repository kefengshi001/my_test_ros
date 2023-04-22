#! usr/bin/env python
"""

import rospy
import tools


if __name__ == "__main__":
    rospy.init_node("aa")               #没有节点时， rospy.loginfo()打印无输出。
    rospy.loginfo("num = %d",tools.num)


#此时用rosrun在终端运行会报错，因为rosrun运行的环境是在工作空间下，运行过程找不到tools文件。
#在scripts文件目录下，在终端通过 python3 test.py运行时候能正常打印输出。

"""

import rospy
import os
import sys

path = os.path.abspath(".")     #rosrun过程中程序执行时的路径

#设置临时环境变量
sys.path.insert(0,path+"/src/plumbing_import/scripts")
import tools

if __name__ == "__main__":
    rospy.init_node("haha")
    # path = os.path.abspath(".")
    # rospy.loginfo("文件执行时的路径：%s",path)  #/home/k/test/demo_03_ws
    rospy.loginfo("num = %d",tools.num)