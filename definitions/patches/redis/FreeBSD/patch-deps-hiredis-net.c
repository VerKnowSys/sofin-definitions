--- deps/hiredis/net.c.orig 2017-04-22 07:23:27.000000000 -0400
+++ deps/hiredis/net.c  2017-05-05 20:02:09.292479000 -0400
@@ -431,7 +451,7 @@
     struct sockaddr_un sa;
     long timeout_msec = -1;

-    if (redisCreateSocket(c,AF_LOCAL) < 0)
+    if (redisCreateSocket(c,AF_UNIX) < 0)
         return REDIS_ERR;
     if (redisSetBlocking(c,0) != REDIS_OK)
         return REDIS_ERR;
@@ -456,7 +476,7 @@
     if (redisContextTimeoutMsec(c,&timeout_msec) != REDIS_OK)
         return REDIS_ERR;

-    sa.sun_family = AF_LOCAL;
+    sa.sun_family = AF_UNIX;
     strncpy(sa.sun_path,path,sizeof(sa.sun_path)-1);
     if (connect(c->fd, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
         if (errno == EINPROGRESS && !blocking) {
