--- ./aclocal.m4.orig	2014-07-10 06:27:16.000000000 +0200
+++ ./aclocal.m4	2014-07-11 11:23:41.000000000 +0200
@@ -47,6 +47,8 @@
     # In bindists, we haven't called AC_CANONICAL_{BUILD,HOST,TARGET}
     # so this justs uses $bootstrap_target.

+    bootstrap_target=`echo "$bootstrap_target" | sed -e 's/-unknown-/-sofin-/g'`
+
     if test "$build_alias" = ""
     then
         if test "$bootstrap_target" != ""
