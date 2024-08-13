<!--
SPDX-License-Identifier: Apache-2.0
SPDX-FileCopyrightText: Canonical Ltd.
-->

# Snapd Test Snap for Nvidia Libraries

This repository contains a test snap designed to be used as a part of snapd
test suite. The snap offers two applications, `32` and `64`, which `dlopen`
graphical support libraries exported from the host system to the snap runtime
environment directory `/var/lib/snapd/lib/gl` (for amd64) and
`/var/lib/snapd/lib/gl32` (for i386).
