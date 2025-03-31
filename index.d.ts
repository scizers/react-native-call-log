export type CallType =
    | 'OUTGOING'
    | 'INCOMING'
    | 'MISSED'
    | 'VOICEMAIL'
    | 'REJECTED'
    | 'BLOCKED'
    | 'ANSWERED_EXTERNALLY'
    | 'UNKNOWN';

export interface CallFilter {
  minTimestamp?: number | string;
  maxTimestamp?: number | string;
  types?: CallType | CallType[];
  phoneNumbers?: string | string[];
}

export interface CallLog {
  phoneNumber: string;
  duration: number;
  name: string;
  timestamp: string;
  dateTime: string;
  type: CallType;
  rawType: number;
}

export default class CallLogs {
  static load(limit: number, filter?: CallFilter): Promise<CallLog[]>;
  static loadAll(): Promise<CallLog[]>;
}
