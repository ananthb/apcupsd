/*
 * This C file has been generated by smidump 0.2.16.
 * It is intended to be used with the NET-SNMP library.
 *
 * This C file is derived from the UPS-MIB module.
 *
 * $Id: rfc1628-mib-mgr.c,v 1.2 2004-02-12 19:42:57 kerns Exp $
 */

#include "apc.h"

#include <stdlib.h>
 
#undef UCD_COMPATIBLE
#define UCD_COMPATIBLE 1

#include <ucd-snmp/asn1.h>
#include <ucd-snmp/snmp.h>
#include <ucd-snmp/snmp_api.h>
#include <ucd-snmp/snmp_client.h>

#include "rfc1628-mib.h"

static oid upsIdentManufacturer[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 1};
static oid upsIdentModel[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 2};
static oid upsIdentUPSSoftwareVersion[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 3};
static oid upsIdentAgentSoftwareVersion[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 4};
static oid upsIdentName[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 5};
static oid upsIdentAttachedDevices[] = {1, 3, 6, 1, 2, 1, 33, 1, 1, 6};
static oid upsBatteryStatus[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 1};
static oid upsSecondsOnBattery[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 2};
static oid upsEstimatedMinutesRemaining[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 3};
static oid upsEstimatedChargeRemaining[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 4};
static oid upsBatteryVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 5};
static oid upsBatteryCurrent[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 6};
static oid upsBatteryTemperature[] = {1, 3, 6, 1, 2, 1, 33, 1, 2, 7};
static oid upsInputLineBads[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 1};
static oid upsInputNumLines[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 2};
/* static oid upsInputLineIndex[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 3, 1, 1}; */
static oid upsInputFrequency[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 3, 1, 2};
static oid upsInputVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 3, 1, 3};
static oid upsInputCurrent[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 3, 1, 4};
static oid upsInputTruePower[] = {1, 3, 6, 1, 2, 1, 33, 1, 3, 3, 1, 5};
static oid upsOutputSource[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 1};
static oid upsOutputFrequency[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 2};
static oid upsOutputNumLines[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 3};
/* static oid upsOutputLineIndex[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 4, 1, 1};   */
static oid upsOutputVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 4, 1, 2};
static oid upsOutputCurrent[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 4, 1, 3};
static oid upsOutputPower[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 4, 1, 4};
static oid upsOutputPercentLoad[] = {1, 3, 6, 1, 2, 1, 33, 1, 4, 4, 1, 5};
static oid upsBypassFrequency[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 1};
static oid upsBypassNumLines[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 2};
/* static oid upsBypassLineIndex[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 3, 1, 1}; */
static oid upsBypassVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 3, 1, 2};
static oid upsBypassCurrent[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 3, 1, 3};
static oid upsBypassPower[] = {1, 3, 6, 1, 2, 1, 33, 1, 5, 3, 1, 4};
static oid upsAlarmsPresent[] = {1, 3, 6, 1, 2, 1, 33, 1, 6, 1};
/* static oid upsAlarmId[] = {1, 3, 6, 1, 2, 1, 33, 1, 6, 2, 1, 1}; */
static oid upsAlarmDescr[] = {1, 3, 6, 1, 2, 1, 33, 1, 6, 2, 1, 2};
static oid upsAlarmTime[] = {1, 3, 6, 1, 2, 1, 33, 1, 6, 2, 1, 3};
static oid upsTestId[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 1};
static oid upsTestSpinLock[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 2};
static oid upsTestResultsSummary[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 3};
static oid upsTestResultsDetail[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 4};
static oid upsTestStartTime[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 5};
static oid upsTestElapsedTime[] = {1, 3, 6, 1, 2, 1, 33, 1, 7, 6};
static oid upsShutdownType[] = {1, 3, 6, 1, 2, 1, 33, 1, 8, 1};
static oid upsShutdownAfterDelay[] = {1, 3, 6, 1, 2, 1, 33, 1, 8, 2};
static oid upsStartupAfterDelay[] = {1, 3, 6, 1, 2, 1, 33, 1, 8, 3};
static oid upsRebootWithDuration[] = {1, 3, 6, 1, 2, 1, 33, 1, 8, 4};
static oid upsAutoRestart[] = {1, 3, 6, 1, 2, 1, 33, 1, 8, 5};
static oid upsConfigInputVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 1};
static oid upsConfigInputFreq[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 2};
static oid upsConfigOutputVoltage[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 3};
static oid upsConfigOutputFreq[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 4};
static oid upsConfigOutputVA[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 5};
static oid upsConfigOutputPower[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 6};
static oid upsConfigLowBattTime[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 7};
static oid upsConfigAudibleStatus[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 8};
static oid upsConfigLowVoltageTransferPoint[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 9};
static oid upsConfigHighVoltageTransferPoint[] = {1, 3, 6, 1, 2, 1, 33, 1, 9, 10};

int ups_mib_mgr_get_upsIdent(struct snmp_session *s, upsIdent_t **upsIdent)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsIdentManufacturer, sizeof(upsIdentManufacturer)/sizeof(oid));
    snmp_add_null_var(request, upsIdentModel, sizeof(upsIdentModel)/sizeof(oid));
    snmp_add_null_var(request, upsIdentUPSSoftwareVersion, sizeof(upsIdentUPSSoftwareVersion)/sizeof(oid));
    snmp_add_null_var(request, upsIdentAgentSoftwareVersion, sizeof(upsIdentAgentSoftwareVersion)/sizeof(oid));
    snmp_add_null_var(request, upsIdentName, sizeof(upsIdentName)/sizeof(oid));
    snmp_add_null_var(request, upsIdentAttachedDevices, sizeof(upsIdentAttachedDevices)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsIdent = (upsIdent_t *) malloc(sizeof(upsIdent_t));
    if (! *upsIdent) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsIdentManufacturer)/sizeof(oid)
	    && memcmp(vars->name, upsIdentManufacturer, sizeof(upsIdentManufacturer)) == 0) {
	    memcpy((*upsIdent)->__upsIdentManufacturer, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentManufacturerLength = vars->val_len;
	    (*upsIdent)->upsIdentManufacturer = (*upsIdent)->__upsIdentManufacturer;
	}
	if (vars->name_length > sizeof(upsIdentModel)/sizeof(oid)
	    && memcmp(vars->name, upsIdentModel, sizeof(upsIdentModel)) == 0) {
	    memcpy((*upsIdent)->__upsIdentModel, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentModelLength = vars->val_len;
	    (*upsIdent)->upsIdentModel = (*upsIdent)->__upsIdentModel;
	}
	if (vars->name_length > sizeof(upsIdentUPSSoftwareVersion)/sizeof(oid)
	    && memcmp(vars->name, upsIdentUPSSoftwareVersion, sizeof(upsIdentUPSSoftwareVersion)) == 0) {
	    memcpy((*upsIdent)->__upsIdentUPSSoftwareVersion, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentUPSSoftwareVersionLength = vars->val_len;
	    (*upsIdent)->upsIdentUPSSoftwareVersion = (*upsIdent)->__upsIdentUPSSoftwareVersion;
	}
	if (vars->name_length > sizeof(upsIdentAgentSoftwareVersion)/sizeof(oid)
	    && memcmp(vars->name, upsIdentAgentSoftwareVersion, sizeof(upsIdentAgentSoftwareVersion)) == 0) {
	    memcpy((*upsIdent)->__upsIdentAgentSoftwareVersion, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentAgentSoftwareVersionLength = vars->val_len;
	    (*upsIdent)->upsIdentAgentSoftwareVersion = (*upsIdent)->__upsIdentAgentSoftwareVersion;
	}
	if (vars->name_length > sizeof(upsIdentName)/sizeof(oid)
	    && memcmp(vars->name, upsIdentName, sizeof(upsIdentName)) == 0) {
	    memcpy((*upsIdent)->__upsIdentName, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentNameLength = vars->val_len;
	    (*upsIdent)->upsIdentName = (*upsIdent)->__upsIdentName;
	}
	if (vars->name_length > sizeof(upsIdentAttachedDevices)/sizeof(oid)
	    && memcmp(vars->name, upsIdentAttachedDevices, sizeof(upsIdentAttachedDevices)) == 0) {
	    memcpy((*upsIdent)->__upsIdentAttachedDevices, vars->val.string, vars->val_len);
	    (*upsIdent)->_upsIdentAttachedDevicesLength = vars->val_len;
	    (*upsIdent)->upsIdentAttachedDevices = (*upsIdent)->__upsIdentAttachedDevices;
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsBattery(struct snmp_session *s, upsBattery_t **upsBattery)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsBatteryStatus, sizeof(upsBatteryStatus)/sizeof(oid));
    snmp_add_null_var(request, upsSecondsOnBattery, sizeof(upsSecondsOnBattery)/sizeof(oid));
    snmp_add_null_var(request, upsEstimatedMinutesRemaining, sizeof(upsEstimatedMinutesRemaining)/sizeof(oid));
    snmp_add_null_var(request, upsEstimatedChargeRemaining, sizeof(upsEstimatedChargeRemaining)/sizeof(oid));
    snmp_add_null_var(request, upsBatteryVoltage, sizeof(upsBatteryVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsBatteryCurrent, sizeof(upsBatteryCurrent)/sizeof(oid));
    snmp_add_null_var(request, upsBatteryTemperature, sizeof(upsBatteryTemperature)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsBattery = (upsBattery_t *) malloc(sizeof(upsBattery_t));
    if (! *upsBattery) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsBatteryStatus)/sizeof(oid)
	    && memcmp(vars->name, upsBatteryStatus, sizeof(upsBatteryStatus)) == 0) {
	    (*upsBattery)->__upsBatteryStatus = *vars->val.integer;
	    (*upsBattery)->upsBatteryStatus = &((*upsBattery)->__upsBatteryStatus);
	}
	if (vars->name_length > sizeof(upsSecondsOnBattery)/sizeof(oid)
	    && memcmp(vars->name, upsSecondsOnBattery, sizeof(upsSecondsOnBattery)) == 0) {
	    (*upsBattery)->__upsSecondsOnBattery = *vars->val.integer;
	    (*upsBattery)->upsSecondsOnBattery = &((*upsBattery)->__upsSecondsOnBattery);
	}
	if (vars->name_length > sizeof(upsEstimatedMinutesRemaining)/sizeof(oid)
	    && memcmp(vars->name, upsEstimatedMinutesRemaining, sizeof(upsEstimatedMinutesRemaining)) == 0) {
	    (*upsBattery)->__upsEstimatedMinutesRemaining = *vars->val.integer;
	    (*upsBattery)->upsEstimatedMinutesRemaining = &((*upsBattery)->__upsEstimatedMinutesRemaining);
	}
	if (vars->name_length > sizeof(upsEstimatedChargeRemaining)/sizeof(oid)
	    && memcmp(vars->name, upsEstimatedChargeRemaining, sizeof(upsEstimatedChargeRemaining)) == 0) {
	    (*upsBattery)->__upsEstimatedChargeRemaining = *vars->val.integer;
	    (*upsBattery)->upsEstimatedChargeRemaining = &((*upsBattery)->__upsEstimatedChargeRemaining);
	}
	if (vars->name_length > sizeof(upsBatteryVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsBatteryVoltage, sizeof(upsBatteryVoltage)) == 0) {
	    (*upsBattery)->__upsBatteryVoltage = *vars->val.integer;
	    (*upsBattery)->upsBatteryVoltage = &((*upsBattery)->__upsBatteryVoltage);
	}
	if (vars->name_length > sizeof(upsBatteryCurrent)/sizeof(oid)
	    && memcmp(vars->name, upsBatteryCurrent, sizeof(upsBatteryCurrent)) == 0) {
	    (*upsBattery)->__upsBatteryCurrent = *vars->val.integer;
	    (*upsBattery)->upsBatteryCurrent = &((*upsBattery)->__upsBatteryCurrent);
	}
	if (vars->name_length > sizeof(upsBatteryTemperature)/sizeof(oid)
	    && memcmp(vars->name, upsBatteryTemperature, sizeof(upsBatteryTemperature)) == 0) {
	    (*upsBattery)->__upsBatteryTemperature = *vars->val.integer;
	    (*upsBattery)->upsBatteryTemperature = &((*upsBattery)->__upsBatteryTemperature);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsInput(struct snmp_session *s, upsInput_t **upsInput)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsInputLineBads, sizeof(upsInputLineBads)/sizeof(oid));
    snmp_add_null_var(request, upsInputNumLines, sizeof(upsInputNumLines)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsInput = (upsInput_t *) malloc(sizeof(upsInput_t));
    if (! *upsInput) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsInputLineBads)/sizeof(oid)
	    && memcmp(vars->name, upsInputLineBads, sizeof(upsInputLineBads)) == 0) {
	    (*upsInput)->__upsInputLineBads = *vars->val.integer;
	    (*upsInput)->upsInputLineBads = &((*upsInput)->__upsInputLineBads);
	}
	if (vars->name_length > sizeof(upsInputNumLines)/sizeof(oid)
	    && memcmp(vars->name, upsInputNumLines, sizeof(upsInputNumLines)) == 0) {
	    (*upsInput)->__upsInputNumLines = *vars->val.integer;
	    (*upsInput)->upsInputNumLines = &((*upsInput)->__upsInputNumLines);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsInputEntry(struct snmp_session *s, upsInputEntry_t **upsInputEntry)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsInputFrequency, sizeof(upsInputFrequency)/sizeof(oid));
    snmp_add_null_var(request, upsInputVoltage, sizeof(upsInputVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsInputCurrent, sizeof(upsInputCurrent)/sizeof(oid));
    snmp_add_null_var(request, upsInputTruePower, sizeof(upsInputTruePower)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsInputEntry = (upsInputEntry_t *) malloc(sizeof(upsInputEntry_t));
    if (! *upsInputEntry) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsInputFrequency)/sizeof(oid)
	    && memcmp(vars->name, upsInputFrequency, sizeof(upsInputFrequency)) == 0) {
	    (*upsInputEntry)->__upsInputFrequency = *vars->val.integer;
	    (*upsInputEntry)->upsInputFrequency = &((*upsInputEntry)->__upsInputFrequency);
	}
	if (vars->name_length > sizeof(upsInputVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsInputVoltage, sizeof(upsInputVoltage)) == 0) {
	    (*upsInputEntry)->__upsInputVoltage = *vars->val.integer;
	    (*upsInputEntry)->upsInputVoltage = &((*upsInputEntry)->__upsInputVoltage);
	}
	if (vars->name_length > sizeof(upsInputCurrent)/sizeof(oid)
	    && memcmp(vars->name, upsInputCurrent, sizeof(upsInputCurrent)) == 0) {
	    (*upsInputEntry)->__upsInputCurrent = *vars->val.integer;
	    (*upsInputEntry)->upsInputCurrent = &((*upsInputEntry)->__upsInputCurrent);
	}
	if (vars->name_length > sizeof(upsInputTruePower)/sizeof(oid)
	    && memcmp(vars->name, upsInputTruePower, sizeof(upsInputTruePower)) == 0) {
	    (*upsInputEntry)->__upsInputTruePower = *vars->val.integer;
	    (*upsInputEntry)->upsInputTruePower = &((*upsInputEntry)->__upsInputTruePower);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsOutput(struct snmp_session *s, upsOutput_t **upsOutput)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsOutputSource, sizeof(upsOutputSource)/sizeof(oid));
    snmp_add_null_var(request, upsOutputFrequency, sizeof(upsOutputFrequency)/sizeof(oid));
    snmp_add_null_var(request, upsOutputNumLines, sizeof(upsOutputNumLines)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsOutput = (upsOutput_t *) malloc(sizeof(upsOutput_t));
    if (! *upsOutput) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsOutputSource)/sizeof(oid)
	    && memcmp(vars->name, upsOutputSource, sizeof(upsOutputSource)) == 0) {
	    (*upsOutput)->__upsOutputSource = *vars->val.integer;
	    (*upsOutput)->upsOutputSource = &((*upsOutput)->__upsOutputSource);
	}
	if (vars->name_length > sizeof(upsOutputFrequency)/sizeof(oid)
	    && memcmp(vars->name, upsOutputFrequency, sizeof(upsOutputFrequency)) == 0) {
	    (*upsOutput)->__upsOutputFrequency = *vars->val.integer;
	    (*upsOutput)->upsOutputFrequency = &((*upsOutput)->__upsOutputFrequency);
	}
	if (vars->name_length > sizeof(upsOutputNumLines)/sizeof(oid)
	    && memcmp(vars->name, upsOutputNumLines, sizeof(upsOutputNumLines)) == 0) {
	    (*upsOutput)->__upsOutputNumLines = *vars->val.integer;
	    (*upsOutput)->upsOutputNumLines = &((*upsOutput)->__upsOutputNumLines);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsOutputEntry(struct snmp_session *s, upsOutputEntry_t **upsOutputEntry)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsOutputVoltage, sizeof(upsOutputVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsOutputCurrent, sizeof(upsOutputCurrent)/sizeof(oid));
    snmp_add_null_var(request, upsOutputPower, sizeof(upsOutputPower)/sizeof(oid));
    snmp_add_null_var(request, upsOutputPercentLoad, sizeof(upsOutputPercentLoad)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsOutputEntry = (upsOutputEntry_t *) malloc(sizeof(upsOutputEntry_t));
    if (! *upsOutputEntry) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsOutputVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsOutputVoltage, sizeof(upsOutputVoltage)) == 0) {
	    (*upsOutputEntry)->__upsOutputVoltage = *vars->val.integer;
	    (*upsOutputEntry)->upsOutputVoltage = &((*upsOutputEntry)->__upsOutputVoltage);
	}
	if (vars->name_length > sizeof(upsOutputCurrent)/sizeof(oid)
	    && memcmp(vars->name, upsOutputCurrent, sizeof(upsOutputCurrent)) == 0) {
	    (*upsOutputEntry)->__upsOutputCurrent = *vars->val.integer;
	    (*upsOutputEntry)->upsOutputCurrent = &((*upsOutputEntry)->__upsOutputCurrent);
	}
	if (vars->name_length > sizeof(upsOutputPower)/sizeof(oid)
	    && memcmp(vars->name, upsOutputPower, sizeof(upsOutputPower)) == 0) {
	    (*upsOutputEntry)->__upsOutputPower = *vars->val.integer;
	    (*upsOutputEntry)->upsOutputPower = &((*upsOutputEntry)->__upsOutputPower);
	}
	if (vars->name_length > sizeof(upsOutputPercentLoad)/sizeof(oid)
	    && memcmp(vars->name, upsOutputPercentLoad, sizeof(upsOutputPercentLoad)) == 0) {
	    (*upsOutputEntry)->__upsOutputPercentLoad = *vars->val.integer;
	    (*upsOutputEntry)->upsOutputPercentLoad = &((*upsOutputEntry)->__upsOutputPercentLoad);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsBypass(struct snmp_session *s, upsBypass_t **upsBypass)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsBypassFrequency, sizeof(upsBypassFrequency)/sizeof(oid));
    snmp_add_null_var(request, upsBypassNumLines, sizeof(upsBypassNumLines)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsBypass = (upsBypass_t *) malloc(sizeof(upsBypass_t));
    if (! *upsBypass) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsBypassFrequency)/sizeof(oid)
	    && memcmp(vars->name, upsBypassFrequency, sizeof(upsBypassFrequency)) == 0) {
	    (*upsBypass)->__upsBypassFrequency = *vars->val.integer;
	    (*upsBypass)->upsBypassFrequency = &((*upsBypass)->__upsBypassFrequency);
	}
	if (vars->name_length > sizeof(upsBypassNumLines)/sizeof(oid)
	    && memcmp(vars->name, upsBypassNumLines, sizeof(upsBypassNumLines)) == 0) {
	    (*upsBypass)->__upsBypassNumLines = *vars->val.integer;
	    (*upsBypass)->upsBypassNumLines = &((*upsBypass)->__upsBypassNumLines);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsBypassEntry(struct snmp_session *s, upsBypassEntry_t **upsBypassEntry)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsBypassVoltage, sizeof(upsBypassVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsBypassCurrent, sizeof(upsBypassCurrent)/sizeof(oid));
    snmp_add_null_var(request, upsBypassPower, sizeof(upsBypassPower)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsBypassEntry = (upsBypassEntry_t *) malloc(sizeof(upsBypassEntry_t));
    if (! *upsBypassEntry) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsBypassVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsBypassVoltage, sizeof(upsBypassVoltage)) == 0) {
	    (*upsBypassEntry)->__upsBypassVoltage = *vars->val.integer;
	    (*upsBypassEntry)->upsBypassVoltage = &((*upsBypassEntry)->__upsBypassVoltage);
	}
	if (vars->name_length > sizeof(upsBypassCurrent)/sizeof(oid)
	    && memcmp(vars->name, upsBypassCurrent, sizeof(upsBypassCurrent)) == 0) {
	    (*upsBypassEntry)->__upsBypassCurrent = *vars->val.integer;
	    (*upsBypassEntry)->upsBypassCurrent = &((*upsBypassEntry)->__upsBypassCurrent);
	}
	if (vars->name_length > sizeof(upsBypassPower)/sizeof(oid)
	    && memcmp(vars->name, upsBypassPower, sizeof(upsBypassPower)) == 0) {
	    (*upsBypassEntry)->__upsBypassPower = *vars->val.integer;
	    (*upsBypassEntry)->upsBypassPower = &((*upsBypassEntry)->__upsBypassPower);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsAlarm(struct snmp_session *s, upsAlarm_t **upsAlarm)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsAlarmsPresent, sizeof(upsAlarmsPresent)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsAlarm = (upsAlarm_t *) malloc(sizeof(upsAlarm_t));
    if (! *upsAlarm) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsAlarmsPresent)/sizeof(oid)
	    && memcmp(vars->name, upsAlarmsPresent, sizeof(upsAlarmsPresent)) == 0) {
	    (*upsAlarm)->__upsAlarmsPresent = *vars->val.integer;
	    (*upsAlarm)->upsAlarmsPresent = &((*upsAlarm)->__upsAlarmsPresent);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsAlarmEntry(struct snmp_session *s, upsAlarmEntry_t **upsAlarmEntry)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsAlarmDescr, sizeof(upsAlarmDescr)/sizeof(oid));
    snmp_add_null_var(request, upsAlarmTime, sizeof(upsAlarmTime)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsAlarmEntry = (upsAlarmEntry_t *) malloc(sizeof(upsAlarmEntry_t));
    if (! *upsAlarmEntry) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsAlarmDescr)/sizeof(oid)
	    && memcmp(vars->name, upsAlarmDescr, sizeof(upsAlarmDescr)) == 0) {
	}
	if (vars->name_length > sizeof(upsAlarmTime)/sizeof(oid)
	    && memcmp(vars->name, upsAlarmTime, sizeof(upsAlarmTime)) == 0) {
	    (*upsAlarmEntry)->__upsAlarmTime = *vars->val.integer;
	    (*upsAlarmEntry)->upsAlarmTime = &((*upsAlarmEntry)->__upsAlarmTime);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsTest(struct snmp_session *s, upsTest_t **upsTest)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsTestId, sizeof(upsTestId)/sizeof(oid));
    snmp_add_null_var(request, upsTestSpinLock, sizeof(upsTestSpinLock)/sizeof(oid));
    snmp_add_null_var(request, upsTestResultsSummary, sizeof(upsTestResultsSummary)/sizeof(oid));
    snmp_add_null_var(request, upsTestResultsDetail, sizeof(upsTestResultsDetail)/sizeof(oid));
    snmp_add_null_var(request, upsTestStartTime, sizeof(upsTestStartTime)/sizeof(oid));
    snmp_add_null_var(request, upsTestElapsedTime, sizeof(upsTestElapsedTime)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsTest = (upsTest_t *) malloc(sizeof(upsTest_t));
    if (! *upsTest) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsTestId)/sizeof(oid)
	    && memcmp(vars->name, upsTestId, sizeof(upsTestId)) == 0) {
	}
	if (vars->name_length > sizeof(upsTestSpinLock)/sizeof(oid)
	    && memcmp(vars->name, upsTestSpinLock, sizeof(upsTestSpinLock)) == 0) {
	    (*upsTest)->__upsTestSpinLock = *vars->val.integer;
	    (*upsTest)->upsTestSpinLock = &((*upsTest)->__upsTestSpinLock);
	}
	if (vars->name_length > sizeof(upsTestResultsSummary)/sizeof(oid)
	    && memcmp(vars->name, upsTestResultsSummary, sizeof(upsTestResultsSummary)) == 0) {
	    (*upsTest)->__upsTestResultsSummary = *vars->val.integer;
	    (*upsTest)->upsTestResultsSummary = &((*upsTest)->__upsTestResultsSummary);
	}
	if (vars->name_length > sizeof(upsTestResultsDetail)/sizeof(oid)
	    && memcmp(vars->name, upsTestResultsDetail, sizeof(upsTestResultsDetail)) == 0) {
	    memcpy((*upsTest)->__upsTestResultsDetail, vars->val.string, vars->val_len);
	    (*upsTest)->_upsTestResultsDetailLength = vars->val_len;
	    (*upsTest)->upsTestResultsDetail = (*upsTest)->__upsTestResultsDetail;
	}
	if (vars->name_length > sizeof(upsTestStartTime)/sizeof(oid)
	    && memcmp(vars->name, upsTestStartTime, sizeof(upsTestStartTime)) == 0) {
	    (*upsTest)->__upsTestStartTime = *vars->val.integer;
	    (*upsTest)->upsTestStartTime = &((*upsTest)->__upsTestStartTime);
	}
	if (vars->name_length > sizeof(upsTestElapsedTime)/sizeof(oid)
	    && memcmp(vars->name, upsTestElapsedTime, sizeof(upsTestElapsedTime)) == 0) {
	    (*upsTest)->__upsTestElapsedTime = *vars->val.integer;
	    (*upsTest)->upsTestElapsedTime = &((*upsTest)->__upsTestElapsedTime);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsControl(struct snmp_session *s, upsControl_t **upsControl)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsShutdownType, sizeof(upsShutdownType)/sizeof(oid));
    snmp_add_null_var(request, upsShutdownAfterDelay, sizeof(upsShutdownAfterDelay)/sizeof(oid));
    snmp_add_null_var(request, upsStartupAfterDelay, sizeof(upsStartupAfterDelay)/sizeof(oid));
    snmp_add_null_var(request, upsRebootWithDuration, sizeof(upsRebootWithDuration)/sizeof(oid));
    snmp_add_null_var(request, upsAutoRestart, sizeof(upsAutoRestart)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsControl = (upsControl_t *) malloc(sizeof(upsControl_t));
    if (! *upsControl) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsShutdownType)/sizeof(oid)
	    && memcmp(vars->name, upsShutdownType, sizeof(upsShutdownType)) == 0) {
	    (*upsControl)->__upsShutdownType = *vars->val.integer;
	    (*upsControl)->upsShutdownType = &((*upsControl)->__upsShutdownType);
	}
	if (vars->name_length > sizeof(upsShutdownAfterDelay)/sizeof(oid)
	    && memcmp(vars->name, upsShutdownAfterDelay, sizeof(upsShutdownAfterDelay)) == 0) {
	    (*upsControl)->__upsShutdownAfterDelay = *vars->val.integer;
	    (*upsControl)->upsShutdownAfterDelay = &((*upsControl)->__upsShutdownAfterDelay);
	}
	if (vars->name_length > sizeof(upsStartupAfterDelay)/sizeof(oid)
	    && memcmp(vars->name, upsStartupAfterDelay, sizeof(upsStartupAfterDelay)) == 0) {
	    (*upsControl)->__upsStartupAfterDelay = *vars->val.integer;
	    (*upsControl)->upsStartupAfterDelay = &((*upsControl)->__upsStartupAfterDelay);
	}
	if (vars->name_length > sizeof(upsRebootWithDuration)/sizeof(oid)
	    && memcmp(vars->name, upsRebootWithDuration, sizeof(upsRebootWithDuration)) == 0) {
	    (*upsControl)->__upsRebootWithDuration = *vars->val.integer;
	    (*upsControl)->upsRebootWithDuration = &((*upsControl)->__upsRebootWithDuration);
	}
	if (vars->name_length > sizeof(upsAutoRestart)/sizeof(oid)
	    && memcmp(vars->name, upsAutoRestart, sizeof(upsAutoRestart)) == 0) {
	    (*upsControl)->__upsAutoRestart = *vars->val.integer;
	    (*upsControl)->upsAutoRestart = &((*upsControl)->__upsAutoRestart);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}

int ups_mib_mgr_get_upsConfig(struct snmp_session *s, upsConfig_t **upsConfig)
{
    struct snmp_session *peer;
    struct snmp_pdu *request, *response;
    struct variable_list *vars;
    int status;

    request = snmp_pdu_create(SNMP_MSG_GETNEXT);
    snmp_add_null_var(request, upsConfigInputVoltage, sizeof(upsConfigInputVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsConfigInputFreq, sizeof(upsConfigInputFreq)/sizeof(oid));
    snmp_add_null_var(request, upsConfigOutputVoltage, sizeof(upsConfigOutputVoltage)/sizeof(oid));
    snmp_add_null_var(request, upsConfigOutputFreq, sizeof(upsConfigOutputFreq)/sizeof(oid));
    snmp_add_null_var(request, upsConfigOutputVA, sizeof(upsConfigOutputVA)/sizeof(oid));
    snmp_add_null_var(request, upsConfigOutputPower, sizeof(upsConfigOutputPower)/sizeof(oid));
    snmp_add_null_var(request, upsConfigLowBattTime, sizeof(upsConfigLowBattTime)/sizeof(oid));
    snmp_add_null_var(request, upsConfigAudibleStatus, sizeof(upsConfigAudibleStatus)/sizeof(oid));
    snmp_add_null_var(request, upsConfigLowVoltageTransferPoint, sizeof(upsConfigLowVoltageTransferPoint)/sizeof(oid));
    snmp_add_null_var(request, upsConfigHighVoltageTransferPoint, sizeof(upsConfigHighVoltageTransferPoint)/sizeof(oid));

    peer = snmp_open(s);
    if (!peer) {
	return -1;
    }

    status = snmp_synch_response(peer, request, &response);
    if (status != STAT_SUCCESS) {
	return -2;
    }

    *upsConfig = (upsConfig_t *) malloc(sizeof(upsConfig_t));
    if (! *upsConfig) {
	return -4;
    }

    for (vars = response->variables; vars; vars = vars->next_variable) {
	if (vars->name_length > sizeof(upsConfigInputVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsConfigInputVoltage, sizeof(upsConfigInputVoltage)) == 0) {
	    (*upsConfig)->__upsConfigInputVoltage = *vars->val.integer;
	    (*upsConfig)->upsConfigInputVoltage = &((*upsConfig)->__upsConfigInputVoltage);
	}
	if (vars->name_length > sizeof(upsConfigInputFreq)/sizeof(oid)
	    && memcmp(vars->name, upsConfigInputFreq, sizeof(upsConfigInputFreq)) == 0) {
	    (*upsConfig)->__upsConfigInputFreq = *vars->val.integer;
	    (*upsConfig)->upsConfigInputFreq = &((*upsConfig)->__upsConfigInputFreq);
	}
	if (vars->name_length > sizeof(upsConfigOutputVoltage)/sizeof(oid)
	    && memcmp(vars->name, upsConfigOutputVoltage, sizeof(upsConfigOutputVoltage)) == 0) {
	    (*upsConfig)->__upsConfigOutputVoltage = *vars->val.integer;
	    (*upsConfig)->upsConfigOutputVoltage = &((*upsConfig)->__upsConfigOutputVoltage);
	}
	if (vars->name_length > sizeof(upsConfigOutputFreq)/sizeof(oid)
	    && memcmp(vars->name, upsConfigOutputFreq, sizeof(upsConfigOutputFreq)) == 0) {
	    (*upsConfig)->__upsConfigOutputFreq = *vars->val.integer;
	    (*upsConfig)->upsConfigOutputFreq = &((*upsConfig)->__upsConfigOutputFreq);
	}
	if (vars->name_length > sizeof(upsConfigOutputVA)/sizeof(oid)
	    && memcmp(vars->name, upsConfigOutputVA, sizeof(upsConfigOutputVA)) == 0) {
	    (*upsConfig)->__upsConfigOutputVA = *vars->val.integer;
	    (*upsConfig)->upsConfigOutputVA = &((*upsConfig)->__upsConfigOutputVA);
	}
	if (vars->name_length > sizeof(upsConfigOutputPower)/sizeof(oid)
	    && memcmp(vars->name, upsConfigOutputPower, sizeof(upsConfigOutputPower)) == 0) {
	    (*upsConfig)->__upsConfigOutputPower = *vars->val.integer;
	    (*upsConfig)->upsConfigOutputPower = &((*upsConfig)->__upsConfigOutputPower);
	}
	if (vars->name_length > sizeof(upsConfigLowBattTime)/sizeof(oid)
	    && memcmp(vars->name, upsConfigLowBattTime, sizeof(upsConfigLowBattTime)) == 0) {
	    (*upsConfig)->__upsConfigLowBattTime = *vars->val.integer;
	    (*upsConfig)->upsConfigLowBattTime = &((*upsConfig)->__upsConfigLowBattTime);
	}
	if (vars->name_length > sizeof(upsConfigAudibleStatus)/sizeof(oid)
	    && memcmp(vars->name, upsConfigAudibleStatus, sizeof(upsConfigAudibleStatus)) == 0) {
	    (*upsConfig)->__upsConfigAudibleStatus = *vars->val.integer;
	    (*upsConfig)->upsConfigAudibleStatus = &((*upsConfig)->__upsConfigAudibleStatus);
	}
	if (vars->name_length > sizeof(upsConfigLowVoltageTransferPoint)/sizeof(oid)
	    && memcmp(vars->name, upsConfigLowVoltageTransferPoint, sizeof(upsConfigLowVoltageTransferPoint)) == 0) {
	    (*upsConfig)->__upsConfigLowVoltageTransferPoint = *vars->val.integer;
	    (*upsConfig)->upsConfigLowVoltageTransferPoint = &((*upsConfig)->__upsConfigLowVoltageTransferPoint);
	}
	if (vars->name_length > sizeof(upsConfigHighVoltageTransferPoint)/sizeof(oid)
	    && memcmp(vars->name, upsConfigHighVoltageTransferPoint, sizeof(upsConfigHighVoltageTransferPoint)) == 0) {
	    (*upsConfig)->__upsConfigHighVoltageTransferPoint = *vars->val.integer;
	    (*upsConfig)->upsConfigHighVoltageTransferPoint = &((*upsConfig)->__upsConfigHighVoltageTransferPoint);
	}
    }

    if (response) snmp_free_pdu(response);

    if (snmp_close(peer) == 0) {
	return -5;
    }

    return 0;
}
