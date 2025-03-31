// @flow
import type { TurboModule } from 'react-native/Libraries/TurboModule/RCTExport';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  load(limit: number): Promise<Array<Object>>;
  loadWithFilter(limit: number, filter: Object): Promise<Array<Object>>;
  loadAll(): Promise<Array<Object>>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('CallLogs');
