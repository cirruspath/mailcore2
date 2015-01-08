#include "com_libmailcore_IMAPMessage.h"

#include "MCBaseTypes.h"
#include "JavaHandle.h"
#include "TypesUtils.h"
#include "MCIMAPMessage.h"
#include "JavaHTMLRendererTemplateCallback.h"
#include "JavaHTMLRendererIMAPCallback.h"

using namespace mailcore;

#define nativeType IMAPMessage
#define javaType nativeType

MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint32_t, setSequenceNumber, sequenceNumber);
MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint32_t, setUid, uid);
MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint32_t, setSize, size);
MC_JAVA_SYNTHESIZE_SCALAR(jint, MessageFlag, setFlags, flags);
MC_JAVA_SYNTHESIZE_SCALAR(jint, MessageFlag, setOriginalFlags, originalFlags);
MC_JAVA_SYNTHESIZE(Array, setCustomFlags, customFlags);
MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint64_t, setModSeqValue, modSeqValue);
MC_JAVA_SYNTHESIZE(AbstractPart, setMainPart, mainPart);
MC_JAVA_SYNTHESIZE(Array, setGmailLabels, gmailLabels);
MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint64_t, setGmailMessageID, gmailMessageID);
MC_JAVA_SYNTHESIZE_SCALAR(jlong, uint64_t, setGmailThreadID, gmailThreadID);

JNIEXPORT jobject JNICALL Java_com_libmailcore_IMAPMessage_partForPartID
  (JNIEnv * env, jobject obj, jstring partID)
{
    return MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->partForPartID(MC_FROM_JAVA(String, partID)));
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_IMAPMessage_partForContentID
  (JNIEnv * env, jobject obj, jstring contentID)
{
    return MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->partForContentID(MC_FROM_JAVA(String, contentID)));
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_IMAPMessage_partForUniqueID
  (JNIEnv * env, jobject obj, jstring uniqueID)
{
    return MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->partForUniqueID(MC_FROM_JAVA(String, uniqueID)));
}

JNIEXPORT jstring JNICALL Java_com_libmailcore_IMAPMessage_htmlRendering
  (JNIEnv * env, jobject obj, jstring folder, jobject dataCallback, jobject htmlTemplateCallback)
{
    JavaHTMLRendererTemplateCallback * templateCallback = NULL;
    if (htmlTemplateCallback != NULL) {
        templateCallback = new JavaHTMLRendererTemplateCallback(env, htmlTemplateCallback);
    }
    JavaHTMLRendererIMAPCallback * imapCallback = NULL;
    if (dataCallback != NULL) {
        imapCallback = new JavaHTMLRendererIMAPCallback(env, dataCallback);
    }
    jstring result = (jstring) MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->htmlRendering(MC_FROM_JAVA(String, folder), imapCallback, templateCallback));
    if (imapCallback != NULL) {
        delete imapCallback;
    }
    if (templateCallback != NULL) {
        delete templateCallback;
    }
    return result;
}

MC_JAVA_BRIDGE
