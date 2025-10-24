import { createApp } from 'vue';
import './assets/css/style.css';
import App from './App.vue';

import { createI18n } from 'vue-i18n';
import cs from './locales/cs.json';
import en from './locales/en.json';
import type { SupportedLang } from './types';

// Language settings
const supportedLangs: SupportedLang[] = ['cs', 'en'];

const savedLang = localStorage.getItem('lang') as SupportedLang | null;
const detectedLang = (navigator.language.split('-')[0] as SupportedLang);

const locale: SupportedLang = savedLang && supportedLangs.includes(savedLang) ? savedLang : supportedLangs.includes(detectedLang) ? detectedLang : 'en';

const i18n = createI18n({
  legacy: false,
  locale,
  fallbackLocale: 'en',
  messages: { cs, en }
});

// App settings
const app = createApp(App);
app.use(i18n);
app.mount('#app');
