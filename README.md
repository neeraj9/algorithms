# Algorithms Reference Implementation

[![Build Status](https://travis-ci.org/neeraj9/algorithms.svg?branch=master)](https://travis-ci.org/neeraj9/algorithms)
[![Software License](https://img.shields.io/badge/license-ISC-blue.svg?style=flat-square)](LICENSE)

This project provides a set of algorithms implemented in various programming
languages (at present c++) which acts as reference implementation for
fun (and could be for profit). The intention is to illustrate algorithms
and data structures with a strong focus on clarity and clean design.

The prime motivation is to illustrate implementation of algorithms in
various programming languages to enable better understanding and
language implementation of the same. Optimization is not the prime focus,
so whenever required clarity will override optimization within the
implementation.

## Software Dependencies

This framework supports *Gnu/Linux* operating system, but with little change
it can be made to build on any of the POSIX compliant operating system. The
following depencies are required to use this project; namely

* [g++](https://gcc.gnu.org/) v3.8+ or [clang](http://clang.llvm.org/) v3.3+
* [make](https://www.gnu.org/software/make/)

## Development Environment Setup

Although the installation for various GNU/Linux distributions differ but
the dependencies are easily available on any one of them.

### Ubuntu or Debian

The following commands were tested on Ubuntu 14.04 but things should be similar
(if not same) on other releases and Debian.

The following commands needs to be as a system administrator or with sudo
(as shown below) so that the relavent packages are installed in the
system.

If your system is not updated then probably it is a good idea to do that
before installing anything else.

    sudo apt-get update

In case you prefer the GNU GCC compler then install g++

    sudo apt-get install -y g++

Alternatively, you can install the clang compiler as well

    sudo apt-get install -y clang-3.5

### CentOS / Fedora / Redhat

The following commands were tested on Centos 7 but things should be similar
(if not same) on other releases and Fedora or Redhat.

If your system is not updated then probably it is a good idea to do that
before installing anything else.

    sudo yum update

In case you prefer the GNU GCC compler then install g++

    sudo yum install -y gcc-c++

Alternatively, you can install the clang compiler as well

    sudo yum install -y clang

> The versions gcc (g++) and clang which are installed in your (rpm based)
> operating needs to meet the previously mentioned criteria. At the time of
> this writing CentOS 7, Fedora 23, RHEL 7 are the latest releases and works
> well. Anything earlier may not work for you unless you are willing to
> get under the hood and build things on your own.

### Archlinux

If your system is not updated then probably it is a good idea to do that
before installing anything else.

    sudo pacman -Syu

In case you prefer the GNU GCC compler then install g++

    sudo pacman -Sy gcc-multilib

Alternatively, you can install the clang compiler as well

    sudo pacman -Sy clang

## Motivation

## Building

After you are done setting up the development environment the build is
pretty straight-forward (see below).

    git clone https://github.com/neeraj9/algorithms
    cd algorithms 
    make

## Algorithms

This project has the following algoritms:

* graph - Algoritms related to graphs.

### Graph

<table>
    <thead>
        <tr>
            <th>Algorithm</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href="graph/cpp11/adj_list_bfs.cpp">cpp11-adj-list-bfs</a></td>
            <td>C++11 implementation of Breadth First Search with graph represented as an adjencency list.</td>
        </tr>
    </tbody>
</table>

## Authors

* Neeraj Sharma {[github: neeraj9](https://github.com/neeraj9)}

