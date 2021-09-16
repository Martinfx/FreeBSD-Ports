--- cmake/Install.cmake.orig	2021-09-16 14:23:08 UTC
+++ cmake/Install.cmake
@@ -261,14 +261,14 @@ elseif(UNIX)
 
 	set(DEFAULT_FILE_DESTINATION ${CMAKE_INSTALL_DATADIR}/${VENDOR}/AusweisApp2)
 	set(TRANSLATION_DESTINATION ${DEFAULT_FILE_DESTINATION}/${TRANSLATION_DESTINATION})
-	install(TARGETS AusweisApp DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Application)
+	install(TARGETS AusweisApp DESTINATION ${DESTDIR}${CMAKE_INSTALL_BINDIR} COMPONENT Application)
 	configure_file(${PACKAGING_DIR}/linux/${BUNDLE_IDENTIFIER}.metainfo.xml.in ${CMAKE_CURRENT_BINARY_DIR}/${BUNDLE_IDENTIFIER}.metainfo.xml @ONLY)
 	configure_file(${PACKAGING_DIR}/linux/${BUNDLE_IDENTIFIER}.desktop.in ${CMAKE_CURRENT_BINARY_DIR}/${BUNDLE_IDENTIFIER}.desktop @ONLY)
 	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${BUNDLE_IDENTIFIER}.metainfo.xml DESTINATION ${CMAKE_INSTALL_DATADIR}/metainfo COMPONENT Application)
 	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${BUNDLE_IDENTIFIER}.desktop DESTINATION ${CMAKE_INSTALL_DATADIR}/applications COMPONENT Application)
-	install(FILES ${RESOURCES_DIR}/images/npa.svg DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/scalable/apps COMPONENT Application RENAME AusweisApp2.svg)
-	install(FILES ${RESOURCES_DIR}/images/npa.png DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/96x96/apps COMPONENT Application RENAME AusweisApp2.png)
-	install(FILES ${DOCS_DIR}/AusweisApp2.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT Application)
+	install(FILES ${RESOURCES_DIR}/images/npa.svg DESTINATION ${DESTDIR}${CMAKE_INSTALL_DATADIR}/icons/hicolor/scalable/apps COMPONENT Application RENAME AusweisApp2.svg)
+	install(FILES ${RESOURCES_DIR}/images/npa.png DESTINATION $${DESTDIR}{CMAKE_INSTALL_DATADIR}/icons/hicolor/96x96/apps COMPONENT Application RENAME AusweisApp2.png)
+	install(FILES ${DOCS_DIR}/AusweisApp2.1 DESTINATION ${DESTDIR}${CMAKE_INSTALL_MANDIR}/man1 COMPONENT Application)
 endif()
 
 
